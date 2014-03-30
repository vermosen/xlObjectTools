/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/swap/xlInitiateInterestRateSwap/xlInitiateInterestRateSwap.hpp>

        /* enregistre un IRS vanilla */
DLLEXPORT xloper * xlInitiateInterestRateSwap (const char * objectID_,
                                               char * fixedLegId_,
                                               char * floatLegId_,
                                               bool * payFixed_,
                                               xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateInterestRateSwap")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

        QuantLib::vanillaSwap2::Type swapType(* payFixed_ ? 
            QuantLib::vanillaSwap2::Payer : 
            QuantLib::vanillaSwap2::Receiver) ;

            /* préparation des données  */
        std::vector<std::string> legNameVector ;
        std::vector<std::string> legTypesVector ;
        std::vector<bool> payingVector ;

        legNameVector.push_back(fixedLegId_) ;
        legNameVector.push_back(floatLegId_) ;

        legTypesVector.push_back("FixedRateLeg") ;
        legTypesVector.push_back("IborLeg") ;

        payingVector.push_back(swapType == QuantLib::vanillaSwap2::Payer ? true : false) ;
        payingVector.push_back(swapType == QuantLib::vanillaSwap2::Payer ? false : true) ;

            // récupération des jambes
        OH_GET_OBJECT(fixedLegPtr, fixedLegId_, QuantLibAddin::Leg)
        OH_GET_OBJECT(floatLegPtr, floatLegId_, QuantLibAddin::Leg)

            /* construction du value object */
        boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapValueObject> valueObject(
            new QuantLibAddin::ValueObjects::interestRateSwapValueObject(
                std::string(objectID_),
                legNameVector,
                legTypesVector,
                payingVector,
                true)) ;

            /* construction du swap de taux */
        boost::shared_ptr<ObjectHandler::Object> interestRateSwapObject(
            new QuantLibAddin::interestRateSwapObject(
                valueObject,
                fixedLegPtr,
                floatLegPtr,
                swapType,
                true)) ;

        std::string returnValue =
            ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                interestRateSwapObject,
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