/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapNPV/xlSwapNPV.hpp>


	/* Fonction de calcul de la NPV d'un swap ou d'une jambe */
DLLEXPORT xloper * xlSwapNPV (const char * instrumentId_,
                              const char * discountCurveId_,
                              xloper * forwardCurveId_,
                              xloper * trigger_) {


         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlSwapNPV")) ;


         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // validation
                ObjectHandler::validateRange(trigger_, "trigger") ;
                ObjectHandler::validateRange(forwardCurveId_, "forward Curve") ;

                    // conversion des xloper
                ObjectHandler::ConvertOper myOper(* forwardCurveId_) ;

                    // on récupère la courbe de discounting
                OH_GET_OBJECT(discountCurvePtr, 
                              discountCurveId_, 
                              ObjectHandler::Object)

                QuantLib::Handle<QuantLib::YieldTermStructure> discountCurveHandler =
                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(discountCurvePtr) ;

                    // on récupère l'instrument
                OH_GET_REFERENCE(mySwap,
                                 instrumentId_,
                                 QuantLibAddin::interestRateSwapObject,
                                 QuantLib::vanillaSwap2)

                boost::shared_ptr<QuantLib::PricingEngine> myPricingEngine ;

                     // ligature du pricing engine
                if (myOper.missing()) {
                     
                        myPricingEngine = boost::shared_ptr<QuantLib::PricingEngine>(
                            new QuantLib::DiscountingSwapEngine(discountCurveHandler/*, discountCurveHandler*/)) ;

                        //mySwap->setFixingIndex(* discountCurveHandler) ;
                     
                    } else {
                    
                                // on récupère la courbe forward
                            OH_GET_OBJECT(forwardCurvePtr, 
                                          static_cast<std::string>(myOper), 
                                          ObjectHandler::Object)

                            QuantLib::Handle<QuantLib::YieldTermStructure> forwardCurveHandler =
                                QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(forwardCurvePtr) ;

                            myPricingEngine = boost::shared_ptr<QuantLib::PricingEngine>(
                                new QuantLib::DiscountingSwapEngine(discountCurveHandler/*, forwardCurveHandler*/)) ;

                            //mySwap->setFixingIndex(* forwardCurveHandler) ;

                        }

                mySwap->setPricingEngine(myPricingEngine) ;
                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(mySwap->NPV(), returnOper) ;
                return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
				ObjectHandler::scalarToOper(e.what(), returnOper) ;
                return & returnOper ;

        }

} ;