/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_time_series
#define xl_initiate_time_series

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/opertovector.hpp>
#include <ohxl/conversions/validations.hpp>

#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

// registers a time series object
DLLEXPORT char * xlInitiateTimeSeries (const char * objectID_,
                                       const xloper * date_,
                                       const xloper * data_,
                                       xloper * trigger_) ;

#endif
