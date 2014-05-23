/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_interpolated_curve
#define xl_initiate_interpolated_curve

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/ratehelpers.hpp>

#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>
#include <ohxl/conversions/opertovector.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/curve/interpolatedCurve/interpolatedCurveObject.hpp>

// sets the default accuracy
#ifdef _DEBUG
#define CURVE_DEFAULT_ACCURACY 1.0e-6
#else
#define CURVE_DEFAULT_ACCURACY 1.0e-10
#endif

	// register an interpolated curve object
DLLEXPORT char * xlInitiateInterpolatedCurve(const char * objectID_       ,
											 xloper     * calculationDate_,
											 const char * curveCalendarId_,
											 xloper     * helperId_       ,
											 xloper     * trigger_         );

#endif
