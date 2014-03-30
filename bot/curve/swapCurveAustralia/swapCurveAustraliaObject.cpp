/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/swapCurveAustralia/swapCurveAustraliaObject.hpp>

namespace QuantLibAddin {


        swapCurveAustraliaObject::swapCurveAustraliaObject(
										     boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject> & valueObject,
                                             const QuantLib::Date & calculationDate,
                                             const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
                                             const bool & permanent,
                                             const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps,
                                             const std::vector<QuantLib::Date> & jumpDates,
                                             QuantLib::Real accuracy) :

            YieldTermStructure(valueObject, permanent) {

				    libraryObject_ = boost::shared_ptr<QuantLibExtended::swapCurveAustralia> (new
					    QuantLibExtended::swapCurveAustralia(calculationDate,
													         instruments,
													         accuracy)) ;

            }

    swapCurveAustraliaObject::swapCurveAustraliaObject(
										 boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject> & valueObject,
                                         const QuantLib::Date & calculationDate,
                                         const std::vector <std::string> & instrumentTag,
                                         const std::vector <std::string> & maturityTag,
                                         const std::vector <double> & quote,
                                         const QuantLib::Real & convexityFactor,
                                         const boost::shared_ptr<QuantLib::IborIndex> & liborIndex3M,
                                         const boost::shared_ptr<QuantLib::IborIndex> & liborIndex6M,
                                         const QuantLib::Real & meanReversionFactor,
                                         const bool & permanent,
                                         const QuantLib::Real & accuracy) :

        YieldTermStructure(valueObject, permanent) {

                /* 0 - définitions */
            unsigned int j = 0 ;

            std::vector<boost::shared_ptr<QuantLib::RateHelper> > swapCurveHelpers ;

                /* index 6M */
            QL_ENSURE(liborIndex6M->tenor().length() == 6 && 
                      liborIndex6M->tenor().units() == QuantLib::Months, 
                      "unapropriate Index Period") ;

                /* index 3M */
            QL_ENSURE(liborIndex3M->tenor().length() == 3 && 
                      liborIndex3M->tenor().units() == QuantLib::Months, 
                      "unapropriate Index Period") ;

			//	/* le handler de la structure par terme */
			//QuantLib::RelinkableHandle<QuantLib::YieldTermStructure> forecastingTermStructure ;

			//	/* linkage des indexes pour l'interpolation */
			//boost::shared_ptr<QuantLib::IborIndex> modifiedIndex3M = liborIndex3M->clone(forecastingTermStructure) ;

   //         boost::shared_ptr<QuantLib::IborIndex> modifiedIndex6M = liborIndex6M->clone(forecastingTermStructure) ;

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


                            if (std::string(maturityTag[i]) == "O/N") {


                                        // le cas des iborindex O/N
                                    boost::shared_ptr<QuantLib::IborIndex> tempTenor (
                                        new QuantLib::IborIndex("O/N AUD Deposit", 
                                                                ObjectHandler::periodFactory()("O/N"),
                                                                0, QuantLib::AUDCurrency(),
                                                                QuantLib::Australia(),
												                QuantLib::ModifiedFollowing, 
                                                                true, QuantLib::Actual365Fixed())) ;

                                    liborTenor = tempTenor ;                                       
                                
                                
                                } else if (std::string(maturityTag[i]) == "T/N") {
                                
                                
                                        // le cas des iborindex T/N
                                    boost::shared_ptr<QuantLib::IborIndex> tempTenor (
                                        new QuantLib::IborIndex("T/N AUD Deposit", 
                                                                ObjectHandler::periodFactory()("T/N"),
                                                                1, QuantLib::AUDCurrency(),
                                                                QuantLib::Australia(),
												                QuantLib::ModifiedFollowing, 
                                                                true, QuantLib::Actual365Fixed())) ;

                                    liborTenor = tempTenor ;        
                                
                                
                                } else {
                                    
                                    
                                        // le cas des iborindex normaux
                                    boost::shared_ptr<QuantLib::IborIndex> tempTenor (
                                        new QuantLib::IborIndex(maturityTag[i] + " AUD Deposit", 
                                                                ObjectHandler::periodFactory()(maturityTag[i]),
                                                                2, QuantLib::AUDCurrency(),
                                                                QuantLib::Australia(),
												                QuantLib::ModifiedFollowing, 
                                                                true, QuantLib::Actual365Fixed())) ;

                                    liborTenor = tempTenor ;   
                                    
                                    
                                }

                            boost::shared_ptr<QuantLib::Quote> depositRate (
                                new QuantLib::SimpleQuote(quote[i])) ;

                            boost::shared_ptr<QuantLib::DepositRateHelper> depositHelper (
                                new QuantLib::DepositRateHelper(QuantLib::Handle<QuantLib::Quote>(depositRate),
                                                                liborTenor)) ;

                            swapCurveHelpers.push_back(depositHelper) ;

                            j += 1 ;


                        }

                    else if (instrumentTag[i] == "SWAP6M") {

                            boost::shared_ptr<QuantLib::Quote> swapRate (
                                new QuantLib::SimpleQuote(quote[i])) ;

                            boost::shared_ptr<QuantLib::RateHelper> swapHelper(new QuantLib::SwapRateHelper(
                                QuantLib::Handle<QuantLib::Quote>(swapRate),
                                ObjectHandler::periodFactory()(maturityTag[i]),
                                QuantLib::Australia(),
                                QuantLib::Semiannual,
                                QuantLib::ModifiedFollowing,
                                QuantLib::Actual365Fixed(),
                                liborIndex6M)) ;

                            swapCurveHelpers.push_back(swapHelper) ;

                        }

                    else if (instrumentTag[i] == "SWAP3M") {

                            boost::shared_ptr<QuantLib::Quote> swapRate (
                                new QuantLib::SimpleQuote(quote[i])) ;

                            boost::shared_ptr<QuantLib::RateHelper> swapHelper(new QuantLib::SwapRateHelper(
                                QuantLib::Handle<QuantLib::Quote>(swapRate),
                                ObjectHandler::periodFactory()(maturityTag[i]),
                                QuantLib::Australia(),
                                QuantLib::Quarterly,
                                QuantLib::ModifiedFollowing,
                                QuantLib::Actual365Fixed(),
                                liborIndex3M)) ;

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
                    QL_REQUIRE(maturityTag[k].substr(0,2) == "IR", "unknown instrument code") ;

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
                        new QuantLibExtended::futuresConvexityAdjustmentQuote(liborIndex3M,
																			  immDate,
																			  * quoteHandler,
																			  * convexityHandler,
																			  * meanReversionHandler,
																			  calculationDate)) ;

                        /* Création du Handler convexity adjusted */
                    boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > futureAdjustmentHandle (
                        new QuantLib::Handle<QuantLib::Quote>(futureAdjustmentQuote)) ;

                        /* création du Helper des future */
                    boost::shared_ptr<QuantLib::FuturesRateHelper> futureHelper (
                        new QuantLib::FuturesRateHelper(* quoteHandler,
                                                        immDate,
                                                        liborIndex3M,
                                                        * futureAdjustmentHandle)) ;


                        /* si le future settle avant la dernière date de maturité des dépôts */     
                    if (futureHelper->earliestDate() <= firstImmDate) continue ;

                        /* si le future settle après la première date de valeur des swaps (matu du premier swap - 180) */
                    if (futureHelper->earliestDate() >= lastImmDate) continue ;

                    swapCurveHelpers.push_back(futureHelper) ;

                }

            boost::shared_ptr<QuantLibExtended::swapCurveAustralia> myCurve (new
                QuantLibExtended::swapCurveAustralia(calculationDate,
											         swapCurveHelpers,
                                                     accuracy)) ;
			
			//	// relinkage du handler, suppression de l'ancien index et on relinke
			//forecastingTermStructure.linkTo(myCurve) ;

			//liborIndex3M = modifiedIndex3M ;

            //liborIndex6M = modifiedIndex6M ;

			libraryObject_ = myCurve ;


        }


    }
