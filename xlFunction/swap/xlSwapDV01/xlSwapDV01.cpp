/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapDV01/xlSwapDV01.hpp>

        /* Fonction de calcul de l'accrued des instruments */
DLLEXPORT xloper * xlSwapDV01 (const char * instrumentId_,
                               const char * curveId_,
                               const char * conventionId_,
                               xloper * trigger_) {


         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlSwapDV01")) ;


         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                QuantLib::Real returnValue ;

                    // on récupère la courbe
                OH_GET_OBJECT(curvePtr, curveId_, ObjectHandler::Object)

                    // on récupère la convention de taux
                OH_GET_OBJECT(conventionPtr, conventionId_, QuantLibAddin::interestRateConventionObject)

                QuantLib::Handle<QuantLib::YieldTermStructure> curveLibPtr =
                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;

                QuantLib::Handle<QuantLib::Quote> mySpread(
                    new QuantLib::SimpleQuote(1.0 / 100)) ; // 1 bp

                QuantLib::Handle<QuantLib::YieldTermStructure> myShiftedCurve( 
                    new QuantLib::ZeroSpreadedTermStructure(curveLibPtr, 
                                                            mySpread, 
                                                            conventionPtr->compounding(), 
                                                            conventionPtr->frequency(), 
                                                            conventionPtr->daycounter())) ;
                                                            
                    // on récupère l'instrument
                OH_GET_OBJECT(instrumentPtr, instrumentId_, ObjectHandler::Object)

                    /* IRS */
                if (instrumentPtr->properties()->className() == "interestRateSwapValueObject") {
                 
						QuantLib::Handle<QuantLib::vanillaSwap2> swapPtr 
							= QuantLibAddin::CoerceHandle<QuantLibAddin::interestRateSwapObject, 
								QuantLib::vanillaSwap2>()(instrumentPtr) ;

                        returnValue = QuantLib::CashFlows::npv(swapPtr->leg(0),
                                                               ** curveLibPtr,
                                                               QuantLib::Unadjusted, QuantLib::Calendar(),
                                                               false) * swapPtr->receivingLeg(0) ;

                        returnValue += QuantLib::CashFlows::npv(swapPtr->leg(1),
                                                                ** curveLibPtr,
                                                                QuantLib::Unadjusted, QuantLib::Calendar(),
                                                                false) * swapPtr->receivingLeg(1) ;

                        returnValue -= QuantLib::CashFlows::npv(swapPtr->leg(0),
                                                               ** myShiftedCurve,
                                                               QuantLib::Unadjusted, QuantLib::Calendar(),
                                                               false) * swapPtr->receivingLeg(0) ;

                        returnValue -= QuantLib::CashFlows::npv(swapPtr->leg(1),
                                                                ** myShiftedCurve,
                                                                QuantLib::Unadjusted, QuantLib::Calendar(),
                                                                false) * swapPtr->receivingLeg(1) ;

                    }

                    /* jambe fixe */
                else if (instrumentPtr->properties()->className() == "fixedLegAustraliaValueObject" ||
                         instrumentPtr->properties()->className() == "fixedLegUnitedStatesValueObject"||
                         instrumentPtr->properties()->className() == "floatLegAustraliaValueObject" ||
                         instrumentPtr->properties()->className() == "floatLegUnitedStatesValueObject") {


                        OH_GET_REFERENCE(instrumentLibObj, 
                                         instrumentId_, 
                                         QuantLibAddin::Leg,
                                         QuantLib::Leg)

                        returnValue = QuantLib::CashFlows::npv(* instrumentLibObj,
                                                               ** curveLibPtr,
                                                               QuantLib::Unadjusted, QuantLib::Calendar(),
                                                               false) ;

                        returnValue -= QuantLib::CashFlows::npv(* instrumentLibObj,
                                                                ** myShiftedCurve,
                                                                QuantLib::Unadjusted, QuantLib::Calendar(),
                                                                false) ;

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