/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_schur_form
#define xl_schur_form

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>

#include <ql/math/matrixutilities/symmetricschurdecomposition.hpp>

#include <bot/math/ublasMatrix/ublasMatrixObject.hpp>
#include <bot/math/ublasMatrixtoOper/ublasMatrixtoOper.hpp>

#include <qle/math/conversion/ublasMatrixToMatrix.hpp>
#include <qle/math/conversion/matrixToUblasMatrix.hpp>

        /* fonction de calcul de la correlation de deux series */
DLLEXPORT xloper * xlSchurForm(const char * objectID_,
                               const xloper * trigger_) ;

#endif