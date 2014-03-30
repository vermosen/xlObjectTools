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

#include <ohxl/repositoryxl.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>


        /* Fonction de calcul des businessDay d'un jour ouvré */
DLLEXPORT double xlCalendarBusinessDate (double * calculationDate_,
                                         char * calendarID_,
                                         long * spotDays_) ;

#endif
