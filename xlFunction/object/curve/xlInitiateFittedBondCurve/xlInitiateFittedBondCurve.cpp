/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateFittedBondCurve/xlInitiateFittedBondCurve.hpp>

        /* fitting paramétrique d'une courbe */
DLLEXPORT char * xlInitiateFittedBondCurve (const char * objectID_,
                                            const double * calculationDate_,
                                            const double * settlementDays_,
                                            const xloper * instruments_,
                                            const xloper * quote_,
                                            const char * currencyId_,
                                            const char * fittingMethodId_,
                                            const xloper * bondSelectionRule_,
                                            const xloper * trigger_) {

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateFittedBondCurve")) ;

        try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* contrôle sur les codes erreur */
            ObjectHandler::validateRange(trigger_,           "trigger") ;
            ObjectHandler::validateRange(instruments_,       "instruments") ;
            ObjectHandler::validateRange(quote_,             "quote") ;
            ObjectHandler::validateRange(bondSelectionRule_, "bond selection rule") ;

                /* création de la rule de sélection des bonds */
            ObjectHandler::ConvertOper myOper1(* bondSelectionRule_) ;

            QuantLib::bondSelectionRule myRule = 
					(myOper1.missing() ?
                     QuantLib::activeRule() : 
                     ObjectHandler::bondSelectionRuleFactory()(
                         static_cast<std::string>(myOper1))) ;

                /* création des dates et des calendriers */
            QuantLib::Currency curveCurrency =
                ObjectHandler::currencyFactory()(currencyId_) ;

            QuantLib::Calendar curveCalendar =
                ObjectHandler::calendarFactory()(curveCurrency.code()) ;

            QuantLib::Date calculationDate =
                curveCalendar.adjust(QuantLib::Date(static_cast<QuantLib::BigInteger>(* calculationDate_))) ;

            QuantLib::Date settlementDate =
                curveCalendar.advance(calculationDate,
                                      static_cast<QuantLib::BigInteger>(* settlementDays_),
                                      QuantLib::Days) ;

            std::string returnValue ;

                /* conversion des xloper */
            std::vector<std::string> instruments = ObjectHandler::operToVector<std::string>(
                * instruments_, "instruments") ;

            std::vector<QuantLib::Real> quote = ObjectHandler::operToVector<double>(
                * quote_, "quote") ;

            std::vector<boost::shared_ptr<QuantLib::BondHelper> > instrumentsObject ;

                // Création des helpers
            for (unsigned int i = 0 ; i < instruments.size() ; i++) {
                
            try {

                    OH_GET_REFERENCE(instrumentPtr, 
                                     instruments[i], 
                                     QuantLibAddin::Bond,
                                     QuantLib::Bond)

                        // la cotation
                    if (quote[i] == 0.0 || !(instrumentPtr->isTradable())) 

                        throw std::exception() ;


                    boost::shared_ptr<QuantLib::Quote> noteQuote(
                        new QuantLib::SimpleQuote (quote[i])) ;

                        // le Handler
                    QuantLib::RelinkableHandle<QuantLib::Quote> quoteHandle ;
                    
                    quoteHandle.linkTo(noteQuote) ;

                        // le Helper
                    boost::shared_ptr<QuantLib::BondHelper> tempHelper(
                        new QuantLib::BondHelper(quoteHandle, instrumentPtr)) ;

                        // copie du Helper
                    instrumentsObject.push_back(tempHelper) ;

                } catch (std::exception & e) {

                        #ifdef _DEBUG

                            {

                                std::ostringstream oss, iss ;
                                oss << e.what() ;
                                iss << instruments[i] ;
                                std::string returnString = std::string("error with  the instrument ") + 
                                                           iss.str() + 
                                                           std::string(" : ") + 
                                                           oss.str() + 
                                                           std::string("\n") ;

                                OutputDebugString(returnString.c_str()) ;

                            }

                        #endif
                    
                    }
                
                }

                /* selecting the right fitting method */
            OH_GET_OBJECT(fittingMethodTemp, 
                          fittingMethodId_, 
                          ObjectHandler::Object) 

                /* Svensson model with stochastic fitting method */
            if (fittingMethodTemp->properties()->className() == 
                "stochasticFittingValueObject") {

                    OH_GET_REFERENCE(fittingMethodPtr,
                                     fittingMethodId_,
                                     QuantLibAddin::stochasticFittingObject,
                                     QuantLib::stochasticFittingHelper)

                        /* Construction du value object */
                    boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> curveValueObject(
                        new QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject(objectID_,
                                                                                            calculationDate.serialNumber(),
                                                                                            true)) ;

                        /* instanciating the curve */
                    boost::shared_ptr<ObjectHandler::Object> myCurve(
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
                                                                            myCurve,
                                                                            true) ;

                }

            else {
           
                    QL_FAIL("Unknown fitting method") ;
                
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