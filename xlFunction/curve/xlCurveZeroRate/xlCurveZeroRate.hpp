/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_curve_zero_rate
#define xl_curve_zero_rate

#include <qlo/conversions/coercetermstructure.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de du taux zero coupon correspondant à une date */
DLLEXPORT double xlCurveZeroRate (const char * curveId_,
                                  const double * effectiveDate_,
                                  const char * conventionId_,
                                  xloper * trigger_) ;

#endif