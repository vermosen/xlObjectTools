/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/math/xlInitiateMatrix/xlInitiateMatrix.hpp>
#include <ohxl/conversions/opertomatrix.hpp>

        /* fonction de calcul de la moyenne EWMA d'une série suivant un processus log-normal */
DLLEXPORT char * xlInitiateMatrix(const char * objectID_,
                                  const xloper * matrix_,
                                  xloper * trigger_) {

boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlInitiateMatrix")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                /* conversion des xloper */
            //QuantLib::Matrix inputMatrix 
			std::vector<std::vector<double> > inputMatrix
			= ObjectHandler::operToMatrix<double>(*matrix_, std::string("matrix_")) ;
			
                // value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::matrixValueObject> myMatrixValueObject(
                new QuantLibAddin::ValueObjects::matrixValueObject(objectID_,
                                                                   true)) ;

                // new pointeur
            boost::shared_ptr<ObjectHandler::Object> myMatrixObject(
                new QuantLibAddin::matrixObject(myMatrixValueObject,
                                                inputMatrix,
                                                true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    myMatrixObject, 
                                                                    true) ;

            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::stringToChar(returnValue, ret) ;

            return ret ;

    } catch (std::exception & e) {

            static char ret[XL_MAX_STR_LEN] ;
            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
            ObjectHandler::stringToChar(e.what(), ret) ;

            return ret ;

    }

} ;