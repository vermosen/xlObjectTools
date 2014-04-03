/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateFittedBondDiscountCurve/xlInitiateFittedBondDiscountCurve.hpp>

	/* fitting paramétrique d'une courbe */
DLLEXPORT char * xlInitiateFittedBondDiscountCurve (const char * objectID_,
                                                    xloper * evaluationDate_,
                                                    xloper * settlementDate_,
                                                    xloper * instruments_,
                                                    xloper * quote_,
                                                    const char * calendarID_,
                                                    const char * fittingMethodID_,
													const xloper * bondSelectionRule_,
                                                    xloper * trigger_) {

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateFittedBondDiscountCurve")) ;

        try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;


                /* trigger pour provoquer le recalcul */
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

            ObjectHandler::validateRange(instruments_, "instruments") ;

            ObjectHandler::validateRange(quote_, "quotes") ;

            ObjectHandler::validateRange(bondSelectionRule_, "bond selection rule") ;

                /* création de la rule de sélection des bonds */
            ObjectHandler::ConvertOper myOper1(* bondSelectionRule_) ;

            QuantLib::bondSelectionRule myRule = 
					(myOper1.missing() ?
                     QuantLib::activeRule() : 
                     ObjectHandler::bondSelectionRuleFactory()(
                         static_cast<std::string>(myOper1))) ;

                /* pointeurs sur les dates et calendriers */
            QuantLib::Calendar curveCalendar 
                = ObjectHandler::calendarFactory()(calendarID_) ;

                /* evaluation Date */
            ObjectHandler::ConvertOper oper1(* evaluationDate_) ;

            QuantLib::Date evaluationDate(oper1.missing() ? 
                QuantLib::Date() : 
                static_cast<QuantLib::Date>(oper1)) ;

            std::string returnValue ;

                /* conversion des xloper */
            std::vector<std::string> instruments = ObjectHandler::operToVector<std::string>(
                * instruments_, "instruments") ;

            std::vector<QuantLib::Real> quote = ObjectHandler::operToVector<double>(
                * quote_, "quote") ;

            std::vector<boost::shared_ptr<QuantLib::BondHelper> > instrumentsObject ;

                // Récupération des instruments
            for (unsigned int i = 0 ; i < instruments.size() ; i++) {

				try {

						// récupération du Bond
                    OH_GET_REFERENCE(instrumentPtr, 
                                     instruments[i],
                                     QuantLibAddin::Bond, 
                                     QuantLib::Bond)

                        // la cotation
                    if (quote[i] != 0.0 && instrumentPtr->isTradable()) { 

                                // la cotation
                            boost::shared_ptr<QuantLib::Quote> noteQuote(
                                new QuantLib::SimpleQuote (quote[i])) ;

                                // le Handler
                            QuantLib::RelinkableHandle<QuantLib::Quote> quoteHandle ;
                            
                            quoteHandle.linkTo(noteQuote) ;

                                // le Helper
                            boost::shared_ptr<QuantLib::BondHelper> noteHelper(
                                new QuantLib::BondHelper(quoteHandle, instrumentPtr)) ; // suppose être le cp

                                // stockage du Helper
                            instrumentsObject.push_back(noteHelper) ;


                        }

					}
				catch(...) {}

                }

                /* settlement Date */
            ObjectHandler::ConvertOper oper2(* settlementDate_) ;

            QuantLib::Date settlementDate(oper2.missing() ? 
                instrumentsObject[0]->bond()->settlementDate(evaluationDate) : 
                static_cast<QuantLib::Date>(oper2)) ;

                /* selecting the right fitting method */
            OH_GET_OBJECT(fittingMethodTemp, 
						  fittingMethodID_, 
						  ObjectHandler::Object) 

                /* Svensson model with stochastic fitting method */
            if (fittingMethodTemp->properties()->className() == "stochasticSvenssonFittingValueObject") {
                    
                    OH_GET_REFERENCE(fittingMethodPtr,
                                     fittingMethodID_,
                                     QuantLibAddin::stochasticFittingObject,
                                     QuantLib::stochasticFittingHelper)

                        /* Construction du value object */
                    boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> curveValueObject(
                        new QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject(objectID_,
                                                                                            settlementDate.serialNumber(),
                                                                                            true)) ;

                        /* instanciating the curve */
                    boost::shared_ptr<ObjectHandler::Object> myNSSCurve(
                        new QuantLibAddin::fittedBondDiscountCurveObject(
                            curveValueObject,
                            settlementDate,
                            myRule.select(instrumentsObject, settlementDate),
                            * fittingMethodPtr->fittingMethod(),
                            fittingMethodPtr->initialVector(),
                            fittingMethodPtr->randomMatrix(),
                            fittingMethodPtr->accuracy(),
                            fittingMethodPtr->maxEvaluationPercycle(),
                            fittingMethodPtr->cyclesPerThread(),
                            fittingMethodPtr->cycles(),
                            1.000,
                            true)) ;

                        /* putting object in the repository */
                    returnValue =
                        ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                            myNSSCurve,
                                                                            true) ;

                }

            static char ret[XL_MAX_STR_LEN] ;
            ObjectHandler::stringToChar(returnValue, ret) ;
            return ret ;

        } catch (std::exception & e) {

				static char ret[XL_MAX_STR_LEN] ;
                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                ObjectHandler::stringToChar(std::string(e.what()), ret) ;
                return ret ;

            }

    } ;