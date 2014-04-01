/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 22/12/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_svensson_model
#define xl_initiate_svensson_model

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFitting.hpp>

#include <bot/factory/constraint/constraintFactory.hpp>
#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingObject.hpp>
#include <bot/math/matrix/matrixObject.hpp>

DLLEXPORT xloper * xlInitiateSvenssonModel (const char * objectID_,
                                            const xloper * constraintSet_,
                                            const xloper * startVector_,
                                            const xloper * startRandomMatrix_,
                                            const xloper * cyclesPerThread_,
                                            const xloper * totalCycles_,
                                            const xloper * maxEvaluationPerCycle_,
                                            const xloper * accuracy_,
                                            xloper * trigger_) ;

#endif
