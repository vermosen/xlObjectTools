/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_swap_curve_united_states
#define xl_initiate_swap_curve_united_states

#include <bot/index/iborIndex/iborIndexObject.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/opertovector.hpp>

#include <bot/curve/swapCurveUnitedStates/swapCurveUnitedStatesObject.hpp>

#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

#ifdef _DEBUG

#define US_SWAP_ACCURACY 1.0e-6

#else

#define US_SWAP_ACCURACY 1.0e-10

#endif

        /* enregistre une courbe de taux swap */
DLLEXPORT char * xlInitiateSwapCurveUnitedStates (const char * objectID_,
                                                  const double * calculationDate_,
                                                  const xloper * instrumentTag_,
                                                  const xloper * maturityTag_,
                                                  const xloper * quote_,
                                                  const double * convexityFactor_,
                                                  const double * meanRevertingFactor_,
                                                  const char * liborId_,
                                                  xloper * trigger_) ;

#endif
