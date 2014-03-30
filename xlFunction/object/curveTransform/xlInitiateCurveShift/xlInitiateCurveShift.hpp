/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_curve_shift
#define xl_initiate_curve_shift

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/opertovector.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ql/quotes/simplequote.hpp>

#include <bot/curve/CurveShift/CurveShiftObject.hpp>

#include <bot/factory/period/periodFactory.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* enregistre un shift de courbe */
DLLEXPORT xloper * xlInitiateCurveShift(const char * shiftName_,
                                        const xloper * gapVector_,
                                        const xloper * shiftVector_,
                                        const char * conventionId_,
                                        const xloper * trigger_) ;

#endif
