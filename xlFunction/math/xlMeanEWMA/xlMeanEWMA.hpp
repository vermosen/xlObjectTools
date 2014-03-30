/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_mean_ewma
#define xl_mean_ewma

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

#include <bot/math/meanEWMA/meanEWMA.hpp>

        /* fonction de calcul de la moyenne EWMA d'une série */
DLLEXPORT xloper * xlMeanEWMA(const char * timeSeriesId_,
                              const double * decay_,
							  const double * valueDate_,
                              xloper * trigger_) ;

#endif