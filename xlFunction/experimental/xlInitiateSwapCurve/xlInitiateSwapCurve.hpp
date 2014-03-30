/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_swap_curve
#define xl_initiate_swap_curve


#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/opertovector.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/curve/swapCurve/swapCurveObject.hpp>
#include <bot/curve/bootstrapHelper/activeBootstrapHelper.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>

#ifdef _DEBUG

#define SWAP_ACCURACY 1.0e-5

#else

#define SWAP_ACCURACY 1.0e-10

#endif

        /* enregistre une courbe de taux swap */
DLLEXPORT xloper * xlInitiateSwapCurve (const char * objectID_,
                                        const xloper * calculationDate_,
                                        const xloper * curveCalendarId_,
                                        const xloper * helperId_,
                                        const xloper * trigger_) ;

#endif
