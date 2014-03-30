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
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(startVector_, "start Vector") ;

                ObjectHandler::validateRange(lambda_, "lambda") ;

                ObjectHandler::validateRange(accuracy_, "accuracy") ;


                    // les XLOPER
                ObjectHandler::ConvertOper myOper1(* startVector_), 
                                           myOper2(* lambda_),
                                           myOper3(* accuracy_) ;
                

                boost::numeric::ublas::matrix<double> startVector(3, 1, 0.0) ;

                boost::numeric::ublas::matrix<double> dummy(3, 3, 0.0) ;

                if (! myOper1.missing()) {
                
                
                              // on récupère les matrices
                        OH_GET_REFERENCE (tempVector,
                                          static_cast<std::string>(myOper1),
                                          QuantLibAddin::ublasMatrixObject,
                                          boost::numeric::ublas::matrix<double>) ;

                            // contrôles sur les matrices
                        QL_REQUIRE(tempVector->size2() == 1 && tempVector->size1() == 3,
                                   "parameters vector is expected to be 3*1 size") ;  


                        startVector = * tempVector ;


                    }

                boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod> myFittingMethod(
                    new QuantLibExtended::stochasticNelsonSiegelFitting(QuantLib::NoConstraint(), 
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