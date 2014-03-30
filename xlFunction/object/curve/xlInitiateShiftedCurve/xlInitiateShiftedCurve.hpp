/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_shifted_curve
#define xl_shifted_curve

#include <qlo/conversions/coercetermstructure.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/vectortoOper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <bot/curve/interpolatedZeroSpreadedTermStructure/interpolatedZeroSpreadedTermStructureObject.hpp>

#include <bot/curve/curveShift/curveShiftObject.hpp>

        /* fonction permettant de créer une courbe shiftée */
DLLEXPORT char * xlShiftedCurve (const char * shiftedCurveID_,
                                 const char * curveID_,
                                 const char * shiftID_,
                                 const xloper * trigger_) ;

#endif
