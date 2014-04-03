/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/10/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_efficient_constrained_frontier
#define xl_efficient_constrained_frontier

#include <vector>

#include <ohxl/repositoryxl.hpp>
//#include <ohxl/conversions/opertovector.hpp>
#include <ohxl/conversions/validations.hpp>

#include <ql/math/randomnumbers/mt19937uniformrng.hpp>
#include <ql/math/optimization/levenbergmarquardt.hpp>

#include <bot/math/Matrix/MatrixObject.hpp>
#include <bot/math/matrixtoOper/MatrixtoOper.hpp>
#include <bot/factory/constraint/constraintFactory.hpp>
#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

#include <ql/experimental/efficientFrontier/meanVarianceCostFunction.hpp>
#include <ql/experimental/efficientFrontier/efficientFrontierConstraint.hpp>

        /* fonction de calcul de la frontière efficiente contrainte */
DLLEXPORT xloper * xlEfficientConstrainedFrontier(const char * returnVectorId_,
                                                  const char * varCovMatrixId_,
                                                  const double * returnThreshold_,
                                                  const xloper * trigger_) ;

#endif