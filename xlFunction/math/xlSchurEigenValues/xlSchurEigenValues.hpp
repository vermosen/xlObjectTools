/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_schur_eigen_values
#define xl_schur_eigen_values

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>

#include <ql/math/matrixutilities/symmetricschurdecomposition.hpp>

#include <bot/math/matrix/matrixObject.hpp>
#include <bot/math/matrixToOper/matrixToOper.hpp>

// calculates and return Schur decomposition's eigen values
DLLEXPORT xloper * rxlSchurEigenValues(const char   * objectID_,
                                       const xloper * trigger_) ;

#endif