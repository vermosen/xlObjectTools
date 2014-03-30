/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_correlation_matrix_ewma
#define xl_correlation_matrix_ewma

#include <vector>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/opertovector.hpp>
#include <ohxl/conversions/validations.hpp>

#include <bot/math/MatrixtoOper/MatrixtoOper.hpp>

#include <qle/math/timeSeries/deltaTimeSeries/deltaTimeSeries.hpp>

#include <bot/tools/timeSeries/TimeSeriesObject.hpp>
#include <bot/math/covarianceEWMA/covarianceEWMA.hpp>
#include <bot/math/meanEWMA/meanEWMA.hpp>

        /* fonction de calcul de la correlation de plusieurs series */
DLLEXPORT xloper * xlCorrelationMatrixEWMA(const xloper * timeSeriesId_,
                                           const double * decay_,
										   const double * startDate_,
                                           const bool * norm_,
                                           const xloper * trigger_) ;

#endif