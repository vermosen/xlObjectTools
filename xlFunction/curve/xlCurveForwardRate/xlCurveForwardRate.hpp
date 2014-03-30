/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_curve_forward_rate
#define xl_curve_forward_rate

#include <qlo/conversions/coercetermstructure.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul du taux forward */
DLLEXPORT double xlCurveForwardRate (const char * curveId_,
                                     const double * t1_,
                                     const double * t2_,
                                      const char * conventionId_,
                                     xloper * trigger_) ;

#endif