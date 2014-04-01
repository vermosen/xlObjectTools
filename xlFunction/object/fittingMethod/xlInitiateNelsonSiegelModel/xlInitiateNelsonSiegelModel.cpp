/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 22/12/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/fittingMethod/xlInitiateNelsonSiegelModel/xlInitiateNelsonSiegelModel.hpp>

        /* initialise un conteneur de paramètre utile pour un fitting parametrique */
DLLEXPORT xloper * xlInitiateNelsonSiegelModel (const char * objectID_,
                                                const xloper * startVector_,
                                                const xloper * lambda_,
                                                const xloper * accuracy_,
                                                xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateNelsonSiegelModel")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // validation des xlopers
                ObjectHandler::validateRange(trigger_,	   "trigger") ;
                ObjectHandler::validateRange(startVector_, "start Vector") ;
                ObjectHandler::validateRange(lambda_,      "lambda") ;
                ObjectHandler::validateRange(accuracy_,	   "accuracy") ;

                    // les XLOPER
                ObjectHandler::ConvertOper myOper1(* startVector_), 
                                           myOper2(* lambda_),
                                           myOper3(* accuracy_) ;
                
                QuantLib::Array startVector(3, 1, 0.0) ;

                QuantLib::Matrix dummy(3, 3, 0.0) ;

                if (! myOper1.missing()) {
                
                
							// on récupère les matrices
                        OH_GET_REFERENCE (tempVector,
                                          static_cast<std::string>(myOper1),
                                          QuantLibAddin::matrixObject,
                                          QuantLib::Matrix) ;

                            // contrôles sur les matrices
                        QL_REQUIRE (tempVector->rows() == 3 && 
								    tempVector->columns() == 1,
                                    "parameters vector is expected to be 3*1 size") ;  

							// copy the data
						for (QuantLib::Size i = 0; i < tempVector->rows(); i++)
							startVector[i] = (*tempVector)[i][0];

                    }

                boost::shared_ptr<QuantLib::stochasticSimplexFittedBondDiscountCurve::fittingMethod> myFittingMethod(
                    new QuantLib::stochasticNelsonSiegelFitting(QuantLib::NoConstraint(), 
                                                                static_cast<QuantLib::Real>(myOper2))) ;

                    // instanciation de la méthode de fitting
                boost::shared_ptr<QuantLibAddin::ValueObjects::stochasticFittingValueObject> myValueObject(
                    new QuantLibAddin::ValueObjects::stochasticFittingValueObject(objectID_, true)) ;

                    // construction de l'objet
                boost::shared_ptr<QuantLibAddin::stochasticFittingObject> mySvenssonFittingObject(
                    new QuantLibAddin::stochasticFittingObject(
                            myValueObject,
                            myFittingMethod,
                            startVector,
                            dummy,
                            1, 1, 10000,
                            static_cast<QuantLib::Real>(myOper3),
                            true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                        mySvenssonFittingObject,
                                                                        true) ; // on force la réécriture

            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(returnValue, returnOper) ;
            return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(std::string(e.what()), returnOper) ;
                return & returnOper ;

            }

    } ;