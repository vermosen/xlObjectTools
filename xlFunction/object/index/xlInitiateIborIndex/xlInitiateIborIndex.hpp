/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_ibor_index
#define xl_initiate_ibor_index

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/indexes/iborindex.hpp>
#include <qlo/valueobjects/vo_index.hpp>

#include <bot/index/iborIndex/iborIndexObject.hpp>
#include <bot/factory/period/periodFactory.hpp>
#include <bot/factory/currency/currencyFactory.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/factory/daycounter/daycountFactory.hpp>
#include <bot/tools/timeSeries/TimeSeriesObject.hpp>

        /* enregistre un index avec ses fixings */
DLLEXPORT char * xlInitiateIborIndex (const char * objectId_,
                                      const char * indexHistoryId_,
                                      const char * tenor_,
                                      const double * settlementDays_,
                                      const char * fixingCalendar_,
                                      const xloper * bdc_,
                                      const xloper * endOfMonth_,
                                      const char * dayCounter_,
                                      const xloper * trigger_) ;

#endif
