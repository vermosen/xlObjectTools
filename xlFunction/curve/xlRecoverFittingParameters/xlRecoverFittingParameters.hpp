/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_recover_fitting_parameters
#define xl_recover_fitting_parameters

#include <qlo/conversions/coercetermstructure.hpp>
#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

#include <bot/math/ublasMatrixToOper/ublasMatrixToOper.hpp>
#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveObject.hpp>

        /* permet la récupération du vecteur des paramètres de fitting */
DLLEXPORT xloper * xlRecoverFittingParameters (const char * curveId_,
                                               const xloper * trigger_) ;

#endif
