/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_schur_eigen_vector
#define xl_schur_eigen_vector

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>

#include <ql/math/matrixutilities/symmetricschurdecomposition.hpp>

#include <bot/math/matrix/matrixObject.hpp>
#include <bot/math/matrixtoOper/matrixtoOper.hpp>

        /* fonction de calcul de la correlation de deux series */
DLLEXPORT xloper * xlSchurEigenVector(const char * objectID_,
                                      const xloper * trigger_) ;

#endif