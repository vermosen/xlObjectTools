/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_business_date
#define xl_calendar_business_date

#include <ql/time/calendar.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>

#include <ohxl/conversions/scalartooper.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

// calculates the date corresponding to a 
// number of business days in a given calendar
DLLEXPORT xloper * xlCalendarBusinessDate (
	double * calculationDate_,
    char * calendarID_,
    long * spotDays_);

#endif
