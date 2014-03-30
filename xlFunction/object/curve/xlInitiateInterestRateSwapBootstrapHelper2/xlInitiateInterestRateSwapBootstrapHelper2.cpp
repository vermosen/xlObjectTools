/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateInterestRateSwapBootstrapHelper2/xlInitiateInterestRateSwapBootstrapHelper2.hpp>

        /* enregistre un helper pour un swap de taux */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper2 (const char * objectId_,
															   const double * maturityDate_,
															   const char * calendar_,
															   const xloper * settlementDays_,
                                                               const xloper * fixedFrequency_,
                                                               const xloper * fixedDayCount_,
															   const double * fixedRate_,
															   const xloper * floatFrequency_,
                                                               const xloper * floatDayCount_,
															   const char * floatIndex_,
															   const xloper * discountCurve_,
                                                               const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateInterestRateSwapBootstrapHelper2")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

				ObjectHandler::validateRange(settlementDays_, "settlement Days") ;

                ObjectHandler::validateRange(discountCurve_, "discount Curve") ;

				ObjectHandler::validateRange(settlementDays_, "discount Curve") ;

				ObjectHandler::validateRange(fixedFrequency_, "discount Curve") ;

				ObjectHandler::validateRange(fixedDayCount_, "discount Curve") ;

				ObjectHandler::validateRange(floatFrequency_, "discount Curve") ;

				ObjectHandler::validateRange(floatDayCount_, "discount Curve") ;


                    /* récupération des oper */
				ObjectHandler::ConvertOper myOper1(* settlementDays_),
										   myOper2(* discountCurve_) ;


				if (myOper2.missing()) {
					
						
					
					}

				else {
					
					
						
						
					}

                    /* récupération du swap  */
                OH_GET_REFERENCE(swapPtr,
                                 floatIndex_,
                                 QuantLibAddin::interestRateSwapObject,
                                 QuantLibExtended::interestRateSwap)


                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject> mySwapHelperValueObject(
                    new QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject(floatIndex_,
                                                                                                true)) ;


                QuantLib::Handle<QuantLib::Quote> myHandle(
                    boost::shared_ptr<QuantLib::Quote>(
                        new QuantLib::SimpleQuote(* fixedRate_))) ;

                    // instanciation de l'instrument
                boost::shared_ptr<QuantLibAddin::interestRateSwapBootstrapHelperObject> mySwapHelperObject(
                    new QuantLibAddin::interestRateSwapBootstrapHelperObject(mySwapHelperValueObject,
                                                                             myHandle,
                                                                             swapPtr,
                                                                             QuantLib::Handle<QuantLib::YieldTermStructure>(),
                                                                             true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        mySwapHelperObject,
                                                                        true) ;


                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(returnValue, returnOper) ;

                return & returnOper ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    static XLOPER returnOper ;

                    ObjectHandler::scalarToOper(e.what(), returnOper) ;

                    return & returnOper ;


            }


    } ;