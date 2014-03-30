/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_kalman_filter
#define xl_kalman_filter

#include <vector>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/opertovector.hpp>
#include <ohxl/conversions/validations.hpp>

#include <bot/math/ublasMatrixtoOper/ublasMatrixtoOper.hpp>
#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

#include <ql/quantlib.hpp>

        /* fonction de calcul de la correlation de plusieurs series */
DLLEXPORT xloper * xlKalmanFilter(const xloper * seriesId_,
                                  const xloper * trigger_) ;

#endif