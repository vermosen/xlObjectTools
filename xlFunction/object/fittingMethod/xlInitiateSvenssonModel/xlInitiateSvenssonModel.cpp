/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 22/12/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/fittingMethod/xlInitiateSvenssonModel/xlInitiateSvenssonModel.hpp>

        /* initialise un conteneur de paramètre utile pour un fitting parametrique */
DLLEXPORT xloper * xlInitiateSvenssonModel (const char * objectID_,
                                            const xloper * constraintSet_,
                                            const xloper * startVector_,
                                            const xloper * startRandomMatrix_,
                                            const xloper * cyclesPerThread_,
                                            const xloper * totalCycles_,
                                            const xloper * maxEvaluationPerCycle_,
                                            const xloper * accuracy_,
                                            xloper * trigger_) {
    
        
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateSvenssonModel")) ;

         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;
            

                    // validation des xlopers
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(constraintSet_, "constraint Set") ;

                ObjectHandler::validateRange(startVector_, "start Vector") ;

                ObjectHandler::validateRange(startRandomMatrix_, "start Random Matrix") ;

                ObjectHandler::validateRange(cyclesPerThread_, "cycles Per Thread") ;

                ObjectHandler::validateRange(totalCycles_, "total Cycles") ;

                ObjectHandler::validateRange(maxEvaluationPerCycle_, "max Evaluation Per Cycle") ;

                ObjectHandler::validateRange(accuracy_, "accuracy") ;


                    // les XLOPER
                ObjectHandler::ConvertOper myOper1(* constraintSet_), 
                                           myOper2(* startVector_),
                                           myOper3(* startRandomMatrix_),
                                           myOper4(* cyclesPerThread_),
                                           myOper5(* totalCycles_),
                                           myOper6(* maxEvaluationPerCycle_),
                                           myOper7(* accuracy_) ;
                


                boost::numeric::ublas::matrix<double> startVector(6, 1, 0.0) ;


                    // vecteur initial
                if (! myOper2.missing()) {
                
                
                              // on récupère les matrices
                        OH_GET_REFERENCE (tempVector,
                                          static_cast<std::string>(myOper2),
                                          QuantLibAddin::ublasMatrixObject,
                                          boost::numeric::ublas::matrix<double>) ;

                            // contrôles sur les matrices
                        QL_REQUIRE(tempVector->size2() == 1 && tempVector->size1() == 6,
                                   "parameters vector is expected to be 6 * 1 size") ;  


                        startVector = * tempVector ;

                    
                    }


                    // matrice de perturbation
                boost::numeric::ublas::matrix<double> startMatrix(6, 6, 0.0) ;

				startMatrix(0, 0) = 1 ;

				startMatrix(1, 1) = 1 ;

				startMatrix(2, 2) = 1 ;

				startMatrix(3, 3) = 1 ;

				startMatrix(4, 4) = 1 ;

				startMatrix(5, 5) = 1 ;

                if (! myOper3.missing()) {
                
                
                              // on récupère les matrices
                        OH_GET_REFERENCE (tempMatrix,
                                           static_cast<std::string>(myOper3),
                                          QuantLibAddin::ublasMatrixObject,
                                          boost::numeric::ublas::matrix<double>) ;

                            // contrôles sur les matrices
                        QL_REQUIRE(tempMatrix->size2() == 6 && tempMatrix->size1() == 6,
                                   "random matrix is expected to be 6*6 size") ;  


                        startMatrix = * tempMatrix ;

                    
                    }

                QuantLib::Constraint myConstraint(
                    myOper1.missing() ?
                    QuantLib::NoConstraint() : 
                ObjectHandler::constraintFactory()(static_cast<std::string>(myOper1))) ;

                boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod> myFittingMethod(
                    new QuantLibExtended::stochasticSvenssonFitting(myConstraint)) ;


                    // instanciation de la méthode de fitting
                boost::shared_ptr<QuantLibAddin::ValueObjects::stochasticFittingValueObject> myValueObject(
                    new QuantLibAddin::ValueObjects::stochasticFittingValueObject(objectID_, true)) ;

                    // construction de l'objet
                boost::shared_ptr<QuantLibAddin::stochasticFittingObject> mySvenssonFittingObject(
                    new QuantLibAddin::stochasticFittingObject(
                            myValueObject,
                            myFittingMethod,
                            startVector,
                            startMatrix,
                            (myOper4.missing()? 1 : static_cast<long>(myOper4)),
                            (myOper5.missing() ? 1 : static_cast<long>(myOper5)),
                            (myOper6.missing() ? 4000 : static_cast<long>(myOper6)),
                            (myOper7.missing() ? 10e-8 : static_cast<QuantLib::Real>(myOper7)),
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