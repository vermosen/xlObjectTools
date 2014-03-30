/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/swapCurveUnitedStates/swapCurveUnitedStatesObject.hpp>

namespace QuantLibAddin {


    swapCurveUnitedStatesObject::swapCurveUnitedStatesObject(
										 boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject> & valueObject,
                                         const QuantLib::Date & calculationDate,
                                         const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
                                         const bool & permanent,
                                         const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps,
                                         const std::vector<QuantLib::Date> & jumpDates,
                                         QuantLib::Real accuracy) :

        YieldTermStructure(valueObject, permanent) {

				libraryObject_ = boost::shared_ptr<QuantLibExtended::swapCurveUnitedStates> (new
					QuantLibExtended::swapCurveUnitedStates(calculationDate,
													        instruments,
													        accuracy)) ;

		}

    swapCurveUnitedStatesObject::swapCurveUnitedStatesObject(
										 boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject> & valueObject,
                                         const QuantLib::Date & calculationDate,
                                         const std::vector <std::string> & instrumentTag,
                                         const std::vector <std::string> & maturityTag,
                                         const std::vector <double> & quote,
                                         const QuantLib::Real & convexityFactor,
                                         const boost::shared_ptr<QuantLib::IborIndex> & liborIndex,
                                         const QuantLib::Real & meanReversionFactor,
                                         const bool & permanent,
                                         const QuantLib::Real & accuracy) :

        YieldTermStructure(valueObject, permanent) {

                /* 0 - définitions */
            unsigned int j = 0 ;

            std::vector<boost::shared_ptr<QuantLib::RateHelper> > swapCurveHelpers ;

                /* index 3M */
            QL_ENSURE(liborIndex->tenor().length() == 3 && 
                      liborIndex->tenor().units() == QuantLib::Months, 
                      "unapropriate Index Period") ;

                /* les facteurs de convexité et de retour à la moyenne pour les futures */
            boost::shared_ptr<QuantLib::SimpleQuote> convexityQuote (
                new QuantLib::SimpleQuote(convexityFactor)) ;

            boost::shared_ptr<QuantLib::SimpleQuote> meanReversion (
                new QuantLib::SimpleQuote(meanReversionFactor)) ;

            boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > convexityHandler (
                new QuantLib::Handle<QuantLib::Quote>(convexityQuote)) ;

            boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > meanReversionHandler (
                new QuantLib::Handle<QuantLib::Quote>(meanReversion)) ;


                /* 1 - on démarre avec les dépôts */
            for (unsigned long i = 0 ; i < instrumentTag.size() ; i++) {

                if (instrumentTag[i] == "DEPOSIT") {

                    boost::shared_ptr<QuantLib::IborIndex> liborTenor ;

                    if (maturityTag[i] == "O/N" || maturityTag[i] == "ON") {

                                // daily iborIndex
                            boost::shared_ptr<QuantLib::DailyTenorLibor> customTenor (
                                new QuantLib::DailyTenorUSDLibor(0)) ;

                            liborTenor = customTenor ;

                        }

                    else if (maturityTag[i] == "T/N" || maturityTag[i] == "TN") {

                                // daily iborIndex
                            boost::shared_ptr<QuantLib::DailyTenorLibor> customTenor (
                                new QuantLib::DailyTenorUSDLibor(1)) ;

                            liborTenor = customTenor ;

                        }

                    else if (maturityTag[i] == "S/N"  || maturityTag[i] == "SN") {

                                // daily iborIndex
                            boost::shared_ptr<QuantLib::DailyTenorLibor> customTenor (
                                new QuantLib::DailyTenorUSDLibor(2)) ;

                            liborTenor = customTenor ;

                        }

                    else {

                                // le cas des iborindex normaux
                            boost::shared_ptr<QuantLib::IborIndex> customTenor (
                                new QuantLib::IborIndex("custom USDLibor", 
                                                        ObjectHandler::periodFactory()(maturityTag[i]),
                                                        2, QuantLib::USDCurrency(),
                                                        QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement),
														QuantLib::ModifiedFollowing, 
                                                        true, QuantLib::Actual360())) ;

                            liborTenor = customTenor ;

                        }

                    boost::shared_ptr<QuantLib::Quote> depositRate (
                        new QuantLib::SimpleQuote(quote[i])) ;

                    boost::shared_ptr<QuantLib::DepositRateHelper> depositHelper (
                        new QuantLib::DepositRateHelper(QuantLib::Handle<QuantLib::Quote>(depositRate),
                                                        liborTenor)) ;


                    swapCurveHelpers.push_back(depositHelper) ;

                    j += 1 ;

                }

                else if (instrumentTag[i] == "SWAP") {

                    boost::shared_ptr<QuantLib::Quote> swapRate (
                        new QuantLib::SimpleQuote(quote[i])) ;

                    boost::shared_ptr<QuantLib::RateHelper> swapHelper(new QuantLib::SwapRateHelper(
                        QuantLib::Handle<QuantLib::Quote>(swapRate),
                        ObjectHandler::periodFactory()(maturityTag[i]),
                        QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement),
                        QuantLib::Semiannual,
                        QuantLib::ModifiedFollowing,
                        QuantLib::Thirty360(QuantLib::Thirty360::USA),
                        liborIndex)) ;

                    swapCurveHelpers.push_back(swapHelper) ;

                }

            }


                /* 2 - on récupère la dernière date de maturité des dépôts
                   et la première date de valeur des swaps ces deux dates
                   déterminent la plage devant être couverte par les eurodollars
				   avec une petite marge de 6 mois pour le gap entre les ED et
				   les swaps de taux. */

            std::sort(swapCurveHelpers.begin(),
                      swapCurveHelpers.end(),
                      QuantLib::detail::BootstrapHelperSorter()) ;

            QuantLib::Date firstImmDate = swapCurveHelpers[j - 1]->latestDate() ;

            QuantLib::Date lastImmDate(swapCurveHelpers[j]->latestDate().serialNumber() - 180) ;

                /* 3 - on passe aux Futures */
            for (unsigned int k = 0 ; k < instrumentTag.size() ; k++) {

                if (instrumentTag[k] != "FUTURE") continue ;

                        /* contrôles sur le tag de l'instrument */
                    QL_REQUIRE(maturityTag[k].substr(0,2) == "ED", "unknown instrument code") ;

                    QuantLib::Date immDate = 
                        QuantLib::IMM::date(maturityTag[k].substr(2,2), calculationDate) ;

                        /* le jour de la date IMM, bloomberg commence à 
                           coter le contrat suivant -> sécurité */
                    if (immDate <= calculationDate + 10) continue ;

                        // Création des quotes
                    boost::shared_ptr<QuantLib::Quote> futureQuote (
                        new QuantLib::SimpleQuote(quote[k])) ;

                    boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > quoteHandler (
                        new QuantLib::Handle<QuantLib::Quote>(futureQuote)) ;

                        // Création du quote convexity adjusted
                    boost::shared_ptr<QuantLib::Quote> futureAdjustmentQuote (
                        new QuantLibExtended::futuresConvexityAdjustmentQuote(liborIndex,
																			  immDate,
																			  * quoteHandler,
																			  * convexityHandler,
																			  * meanReversionHandler,
																			  calculationDate)) ;

                        // Création du Handler convexity adjusted
                    boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > futureAdjustmentHandle (
                        new QuantLib::Handle<QuantLib::Quote>(futureAdjustmentQuote)) ;

                        // création du Helper des future
                    boost::shared_ptr<QuantLib::FuturesRateHelper> futureHelper (
                        new QuantLib::FuturesRateHelper(* quoteHandler,
                                                        immDate,
                                                        liborIndex,
                                                        * futureAdjustmentHandle)) ;


                        /* si le future mature après la première date de valeur des swaps */
                    if (futureHelper->latestDate() <= firstImmDate) continue ;

                        /* si le future settle avant la dernière date de maturité des dépôts */
                    if (futureHelper->earliestDate() >= lastImmDate) continue ;

                    swapCurveHelpers.push_back(futureHelper) ;

                }

            boost::shared_ptr<QuantLibExtended::swapCurveUnitedStates> myCurve (new
                QuantLibExtended::swapCurveUnitedStates(calculationDate,
											            swapCurveHelpers,
                                                        accuracy)) ;
			
			// suppression de l'ancien index et on relinke
			//forecastingTermStructure.linkTo(myCurve) ;

			//liborIndex = modifiedIndex ;

			libraryObject_ = myCurve ;

    }

}
