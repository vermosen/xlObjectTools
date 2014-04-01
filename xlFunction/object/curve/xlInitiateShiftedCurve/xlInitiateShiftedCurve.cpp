/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateShiftedCurve/xlInitiateShiftedCurve.hpp>

        /* fonction permettant de créer une courbe shiftée */
DLLEXPORT char * xlShiftedCurve (const char * shiftedCurveID_,
                                 const char * curveID_,
                                 const char * shiftID_,
                                 const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlShiftedCurve")) ;

         try {

            QL_REQUIRE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // on récupère la courbe des taux
            OH_GET_OBJECT(curveObjectPtr, curveID_, ObjectHandler::Object)

            QuantLib::Handle<QuantLib::YieldTermStructure> curvePtr
                = QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, 
                        QuantLib::YieldTermStructure>()(curveObjectPtr) ;

                // on récupère le vecteur de shift
            OH_GET_OBJECT(shiftObjectPtr, shiftID_, QuantLibAddin::curveShiftObject)

            std::vector<QuantLib::Handle<QuantLib::gapQuote> > shiftObj = shiftObjectPtr->getcurveShift() ;

                // création du Value Object
            boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedZeroSpreadedTermStructureValueObject> valueObject (
                new QuantLibAddin::ValueObjects::interpolatedZeroSpreadedTermStructureValueObject(shiftedCurveID_, 
                                                                                                  curvePtr->referenceDate().serialNumber(), 
                                                                                                  true)) ;

                // création de l'object
            boost::shared_ptr<ObjectHandler::Object> spreadedTermStructure (
                new QuantLibAddin::interpolatedZeroSpreadedTermStructureObject(valueObject,
                                                                               curvePtr,
                                                                               shiftObj, 
                                                                               true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(shiftedCurveID_,
                                                                    spreadedTermStructure,
                                                                    true) ; // on force la réécriture

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
