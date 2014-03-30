/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlInitiateZeroCouponInflationSwapUnitedStates.hpp"

        /* enregistre un swap inflation zero coupon */
DLLEXPORT xloper * xlInitiateZeroCouponInflationSwapUnitedStates (const char * objectID_,
                                                                  const char * fixedLegId_,
                                                                  const char * inflationLegId_,
                                                                  const bool payFixed_,
                                                                  xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateZeroCouponInflationSwapUnitedStates")) ;

     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;


                // initialisation de la session
            ObjectHandler::validateRange(trigger_, "trigger") ;

                /* on récupère la jambe fixe */
            OH_GET_OBJECT(fixedLegPtr, fixedLegId_, QuantLibAddin::Leg)

                /* on récupère la jambe variable */
            OH_GET_OBJECT(inflationLegPtr, inflationLegId_, QuantLibAddin::Leg)

                /* préparation des données  */
            std::vector<std::string> legNameVector ;

            std::vector<std::string> legTypesVector ;

            std::vector<bool> payingVector ;

            legNameVector.push_back(fixedLegId_) ;

            legNameVector.push_back(inflationLegId_) ;

            legTypesVector.push_back(fixedLegPtr->properties()->className()) ;

            legTypesVector.push_back(inflationLegPtr->properties()->className()) ;

            payingVector.push_back(payFixed_ ? true : false) ;

            payingVector.push_back(payFixed_ ? false : true) ;


                /* construction du value object */
            boost::shared_ptr<QuantLibAddin::ValueObjects::zeroCouponInflationSwapUnitedStatesValueObject> valueObject(
                new QuantLibAddin::ValueObjects::zeroCouponInflationSwapUnitedStatesValueObject(
                    std::string(objectID_),
                    legNameVector,
                    legTypesVector,
                    payingVector,
                    true)) ;

                // construction du swap
            boost::shared_ptr<ObjectHandler::Object> zeroInflationSwapObject(
                new QuantLibAddin::zeroCouponInflationSwapUnitedStatesObject(
                    valueObject,
                    fixedLegPtr,
                    inflationLegPtr,
                    payFixed_,
                    true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    zeroInflationSwapObject, 
                                                                    true) ; // on force la réécriture

            static XLOPER returnOper ;

            ObjectHandler::scalarToOper(returnValue, returnOper) ;

            return & returnOper ;


        } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(e.what(), returnOper) ;

                return & returnOper ;


            }
    
    
    }
