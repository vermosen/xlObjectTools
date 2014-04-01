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
			OH_GET_UNDERLYING(tempmat,
				returnVectorId_,
				QuantLibAddin::matrixObject,
				QuantLib::Matrix)

                /* acquisition de la matrice de variance-covariance */
            OH_GET_UNDERLYING(mat, 
                              varCovMatrixId_, 
							  QuantLibAddin::matrixObject,
                              QuantLib::Matrix)

                /* contrôles */
			QL_REQUIRE(tempmat.rows() == mat.rows() &&
					   tempmat.columns() == 1 &&
                       mat.rows() == mat.columns(), "unapropriate data set") ;

				/*copy vector*/
			QuantLib::Array returnVector(tempmat.rows(), 0.0);
			
			for (QuantLib::Size i = 0; i < tempmat.rows(); i++)
				returnVector[i] = tempmat[i][0];

                /* la dimension du probleme */
            QuantLib::Size problemSize = returnVector.size() ;
            QuantLib::Array myReturnArray = returnVector ;
            QuantLib::Real myReturnThreshold = * returnThreshold_ ;

                /* conversion de la contrainte : creer un scalarBondaryConstraint */
            QuantLib::efficientFrontierConstraint myConstraint(QuantLib::Array(problemSize, 1.0), // upper bound
                                                               QuantLib::Array(problemSize, 0.0), // lower bound
															   returnVector, // return array
                                                               myReturnThreshold) ; // a terme : on peut implementer 2 vecteurs de contraintes

                // creation du simplexe
            QuantLib::LevenbergMarquardt myLevenberg ;
            QuantLib::meanVarianceCostFunction myCostFunction(mat) ;
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

			QuantLib::Array res = problem.currentValue();

            ObjectHandler::VectorToOper(res, returnOper) ;

            return & returnOper ;

            } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
				static XLOPER returnOper ;
				returnOper.xltype = xltypeErr ;
				returnOper.val.err = xlerrValue ;
				return & returnOper ;

            }

    }