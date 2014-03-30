
/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/04/10
 *  Copyright 2009. All rights reserved.
 *
 */


#include <xlFunction/swap/xlSwapFairFixedRate/xlSwapFairFixedRate.hpp>


        /* Fonction de calcul d'un taux fixe de swap */
DLLEXPORT xloper * xlSwapFairFixedRate (const char * swapId_,
                                        const char * legId_,
                                        const char * curveId_,
                                        xloper * trigger_) {


     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlSwapFairFixedRate")) ;

     try {

        QL_REQUIRE(! functionCall->calledByFunctionWizard(), "") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

            // on récupère la courbe des taux
        OH_GET_OBJECT(curvePtr, curveId_, QuantLibAddin::YieldTermStructure)

        QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
            QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;

            // setup de la date de pricing (reference date de la courbe)
        //QuantLib::Settings::instance().evaluationDate() = YieldCurveLibObj->referenceDate() ;

            // on récupère le swap
        OH_GET_OBJECT(objPtr, swapId_, ObjectHandler::Object)

            // calcul de la NPV totale des autres jambes
        QuantLib::Real fairRate  = 0.0 ;

            // objet pour contrôle
        OH_GET_OBJECT(swapObj, swapId_, QuantLibAddin::interestRateSwapObject)

            // on spécialise le ptr
        OH_GET_REFERENCE(swapPtr, 
                         swapId_, 
                         QuantLibAddin::interestRateSwapObject,
                         QuantLib::vanillaSwap2)

            // vérification que la jambe fait partie du swap
        QL_REQUIRE(swapObj->getLegType(std::string(legId_)) == "fixedLegUnitedStatesValueObject" ||
                   swapObj->getLegType(std::string(legId_)) == "fixedLegUnitedAustraliaValueObject", "unappropriate leg type") ;

        swapPtr->setPricingEngine(boost::shared_ptr<QuantLib::PricingEngine>(
            new QuantLib::DiscountingSwapEngine(YieldCurveLibObj))) ;

            // calcul de la NPV totale des autres jambes
        QuantLib::Size legRank = swapObj->getLegRank(std::string(legId_)) ;

            // on suppose que le taux est fixe (pas de step-up cpn)
        boost::shared_ptr<QuantLib::FixedRateCoupon> myCastedCashFlow 
            = boost::dynamic_pointer_cast<QuantLib::FixedRateCoupon>(swapPtr->leg(legRank)[0]) ;

        fairRate = myCastedCashFlow->rate() - swapPtr->NPV()/(swapPtr->legBPS(legRank)/1.0e-4) ;
        static XLOPER returnOper ;
        ObjectHandler::scalarToOper(fairRate, returnOper) ;

        return & returnOper ;

    } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(e.what(), returnOper) ;

            return & returnOper ;

        }

} ;