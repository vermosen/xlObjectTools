/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */
#include <xlFunction/experimental/xlEfficientConstrainedFrontier/xlEfficientConstrainedFrontier.hpp>

        /* fonction de calcul de la frontière eficiente contrainte */
DLLEXPORT xloper * xlEfficientConstrainedFrontier(const char * returnVectorId_,
                                                  const char * varCovMatrixId_,
                                                  const double * returnThreshold_,
                                                  const xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlEfficientConstrainedFrontier")) ;

         try {

            QL_REQUIRE(!functionCall->calledByFunctionWizard(), "") ;

                /* déclaration du trigger */
            ObjectHandler::validateRange(trigger_, "trigger") ;

                /* acquisition du vecteur d'esperance */
            OH_GET_UNDERLYING(returnVector, 
                              returnVectorId_, 
                              QuantLibAddin::MatrixObject,
                              boost::numeric::::matrix<double>)

                /* acquisition de la matrice de variance-covariance */
            OH_GET_UNDERLYING(varCovMatrix, 
                              varCovMatrixId_, 
                              QuantLibAddin::MatrixObject,
                              boost::numeric::::matrix<double>)

                /* contrôles */
            QL_REQUIRE(returnVector.size1() == varCovMatrix.size2() &&
                       varCovMatrix.size1() == varCovMatrix.size2(), "unapropriate data set") ;

                /* la dimension du probleme */
            QuantLib::Size problemSize = returnVector.size1() ;

            QuantLib::Array myReturnArray = QuantLibExtended::MatrixToArray(returnVector) ;

            QuantLib::Real myReturnThreshold = * returnThreshold_ ;

                /* conversion de la contrainte : creer un scalarBondaryConstraint */
            QuantLibExtended::efficientFrontierConstraint myConstraint(QuantLib::Array(problemSize, 1.0), // upper bound
                                                                       QuantLib::Array(problemSize, 0.0), // lower bound
                                                                       myReturnArray, // return array
                                                                       myReturnThreshold) ; // a terme : on peut implementer 2 vecteurs de contraintes

                // creation du simplexe
            QuantLib::LevenbergMarquardt myLevenberg ;

            QuantLibExtended::meanVarianceCostFunction myCostFunction(varCovMatrix) ;

            QuantLib::Problem problem(myCostFunction, myConstraint, QuantLib::Array(problemSize, 1.0 / (problemSize + 1))) ;

            QuantLib::Natural maxStationaryStateIterations = 100 ;

            QuantLib::Natural maxIterations = 10000 ;

            QuantLib::Real rootEpsilon = 10e-8 ;

            QuantLib::Real functionEpsilon =  10e-8 ;

            QuantLib::Real gradientNormEpsilon = 10e-8 ;

            QuantLib::EndCriteria endCriteria(maxIterations,
                                              maxStationaryStateIterations,
                                              rootEpsilon,
                                              functionEpsilon,
                                              gradientNormEpsilon) ;

            myLevenberg.minimize(problem, endCriteria) ;

            static OPER returnOper ;

            ObjectHandler::MatrixToOper(QuantLibExtended::arrayToMatrix(problem.currentValue()), returnOper) ;

            return & returnOper ;

            } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

				static XLOPER returnOper ;

				returnOper.xltype = xltypeErr ;

				returnOper.val.err = xlerrValue ;

				return & returnOper ;


            }

    }