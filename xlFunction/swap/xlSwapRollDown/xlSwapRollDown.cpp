/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 17/01/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapRollDown/xlSwapRollDown.hpp>

        /* Fonction de calcul du roll-down d'un swap */
DLLEXPORT xloper * xlSwapRollDown (const char * instrumentId_,
                                   const char * discountCurveId_,
                                   xloper * forwardCurveId_,
                                   const double * fwdDate_,
								   xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlSwapRollDown")) ;

     try {


        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

            // on récupère l'IRS
        OH_GET_REFERENCE(mySwap,
                         instrumentId_,
                         QuantLibAddin::interestRateSwapObject,
                         QuantLib::vanillaSwap2)


            // on récupère la courbe de taux
        OH_GET_OBJECT(discountCurvePtr, discountCurveId_, ObjectHandler::Object)

        QuantLib::Handle<QuantLib::YieldTermStructure> discountCurveHandle =
            QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(discountCurvePtr) ;

            // établissement des dates de règlement : la spot date est donnée par la courbe
        QuantLib::Date spotDate = discountCurveHandle->referenceDate() ;

        QuantLib::Date fwdDate = QuantLib::Date(static_cast<QuantLib::BigInteger>(* fwdDate_)) ;

            // on construit une implied term structure à la date fwd
        QuantLib::Handle<QuantLib::YieldTermStructure> myImpliedDiscountCurve(
            boost::shared_ptr<QuantLib::YieldTermStructure>(
                new QuantLib::translatedTermStructure(discountCurveHandle, fwdDate))) ;

        boost::shared_ptr<QuantLib::PricingEngine> myPricingEngine(
            new QuantLib::DiscountingSwapEngine(myImpliedDiscountCurve/*, myImpliedDiscountCurve*/)) ;

        mySwap->setPricingEngine(myPricingEngine) ;

		// on voudrait bien relinker...
        //mySwap->setFixingIndex(* myImpliedDiscountCurve) ;

            // variable de retour
        static XLOPER returnOper ;

        ObjectHandler::scalarToOper(mySwap->NPV(), returnOper) ;

        return & returnOper ;


    } catch (std::exception & e) {


            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

            static XLOPER returnOper ;

            ObjectHandler::scalarToOper(e.what(), returnOper) ;

            return & returnOper ;


    }

}