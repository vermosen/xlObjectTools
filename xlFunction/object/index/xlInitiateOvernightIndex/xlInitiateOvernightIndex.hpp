/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 26/11/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_overnight_index
#define xl_initiate_overnight_index

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <qlo/indexes/iborindex.hpp>

#include <qlo/valueobjects/vo_index.hpp>


#include <bot/index/overnightIndex/overnightIndexObject.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

        /* enregistre un index forecaste avec ses fixings */
DLLEXPORT char * xlInitiateOvernightIndex (const char * objectId_,
                                           const xloper * indexHistoryId_,
                                           const xloper * settlementDays_,
                                           const char * fixingCalendar_,
                                           const char * dayCounter_,
                                           const xloper * trigger_) ;


#endif
