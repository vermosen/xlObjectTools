/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_curve_reference_date
#define xl_curve_reference_date

#include <qlo/conversions/coercetermstructure.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>


        /* fournit la date de référence de la courbe */
DLLEXPORT double xlCurveReferenceDate (const char * curveId_,
                                       xloper * trigger_) ;

#endif