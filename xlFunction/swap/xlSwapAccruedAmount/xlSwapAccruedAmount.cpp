/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapAccruedAmount/xlSwapAccruedAmount.hpp>

        /* Fonction de calcul de l'accrued des instruments */
DLLEXPORT xloper * xlSwapAccruedAmount (const char * instrumentId_,
                                        const double * settlementDate_,
                                        xloper * referenceIndex_,
                                        xloper * trigger_) {


         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlSwapAccruedAmount")) ;


         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(referenceIndex_, "reference Index") ;


					// conversion des xloper
                ObjectHandler::ConvertOper myOper(* referenceIndex_) ;


                QuantLib::Real returnValue ;


                    // on récupère l'instrument
                OH_GET_OBJECT(instrumentPtr, instrumentId_, ObjectHandler::Object)


                    /* IRS */
                if (instrumentPtr->properties()->className() == "interestRateSwapValueObject") {
                    

                        OH_GET_REFERENCE(instrumentPtr, 
                                         instrumentId_, 
                                         QuantLibAddin::interestRateSwapObject, 
                                         QuantLib::vanillaSwap2)

                        if (! myOper.missing()) {


                                    // on récupère la courbe de discounting
                                OH_GET_OBJECT(discountCurvePtr, 
                                              static_cast<std::string>(myOper), 
                                              ObjectHandler::Object)

                                QuantLib::Handle<QuantLib::YieldTermStructure> discountCurveHandler =
                                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(discountCurvePtr) ;

                               // instrumentPtr->setFixingIndex(* discountCurveHandler) ;
                

                            }

                        returnValue =  instrumentPtr->accruedAmount(false,
                                                                    QuantLib::Date(static_cast<QuantLib::BigInteger>(* settlementDate_))) ;


                    }

                    /* jambe fixe */
                else if (instrumentPtr->properties()->className() == "fixedLegUnitedStatesValueObject") {


                        OH_GET_REFERENCE(instrumentLibObj, 
                                         instrumentId_, 
                                         QuantLibAddin::fixedLegUnitedStatesObject,
                                         QuantLib::Leg)

                        returnValue = QuantLib::CashFlows::accruedAmount(* instrumentLibObj,
                                                                         false,
                                                                         QuantLib::Date(static_cast<QuantLib::BigInteger>(* settlementDate_))) ;


                    }


                    /* jambe flottante */
                else if (instrumentPtr->properties()->className() == "floatLegUnitedStatesValueObject") {


                        OH_GET_OBJECT(instrumentLibObj, instrumentId_, QuantLibAddin::floatLegUnitedStatesObject)

                        if (! myOper.missing()) {


                                    // on récupère la courbe de discounting
                                OH_GET_OBJECT(discountCurvePtr, 
                                              static_cast<std::string>(myOper), 
                                              ObjectHandler::Object)

                                QuantLib::Handle<QuantLib::YieldTermStructure> discountCurveHandler =
                                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(discountCurvePtr) ;

                                instrumentLibObj->setFixingIndex(discountCurveHandler) ;
                

                            }

                        returnValue = instrumentLibObj->accruedAmount(false,
                                                                      QuantLib::Date(static_cast<QuantLib::BigInteger>(* settlementDate_))) ;


                    }

                    /* jambe fixe */
                else if (instrumentPtr->properties()->className() == "fixedLegAustraliaValueObject") {


                        OH_GET_REFERENCE(instrumentLibObj, 
                                         instrumentId_, 
                                         QuantLibAddin::fixedLegAustraliaObject,
                                         QuantLib::Leg)

                        returnValue = QuantLib::CashFlows::accruedAmount(* instrumentLibObj,
                                                                         false,
                                                                         QuantLib::Date(static_cast<QuantLib::BigInteger>(* settlementDate_))) ;


                    }


                    /* jambe flottante */
                else if (instrumentPtr->properties()->className() == "floatLegAustraliaValueObject") {


                        OH_GET_OBJECT(instrumentLibObj, instrumentId_, QuantLibAddin::floatLegAustraliaObject)

                        if (! myOper.missing()) {


                                    // on récupère la courbe de discounting
                                OH_GET_OBJECT(discountCurvePtr, 
                                              static_cast<std::string>(myOper), 
                                              ObjectHandler::Object)

                                QuantLib::Handle<QuantLib::YieldTermStructure> discountCurveHandler =
                                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(discountCurvePtr) ;

                                instrumentLibObj->setFixingIndex(discountCurveHandler) ;
                

                            }

                        returnValue = instrumentLibObj->accruedAmount(
							false, QuantLib::Date(static_cast<QuantLib::BigInteger>(* settlementDate_))) ;

                    }


                else { // ici pour les autres instruments
                    
                        QL_FAIL("unknown instrument type") ;
                    
                    }

                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(returnValue, returnOper) ;

                return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
                returnOper.xltype = xltypeErr ;
                returnOper.val.err = xlerrValue ;

                return & returnOper ;

        }

} ;