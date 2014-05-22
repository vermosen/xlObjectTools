/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 20/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_period_count
#define xl_calendar_period_count

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/time/calendars/weekendsonly.hpp>

#include <bot/factory/period/periodFactory.hpp>
#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>

	// calculate gap end
DLLEXPORT double xlPeriodCount (xloper * calculationDate_,
                                const char * period_,
                                xloper * calendar_,
                                xloper * endDateConvention_,
                                xloper * endOfMonth_) ;

#endif
