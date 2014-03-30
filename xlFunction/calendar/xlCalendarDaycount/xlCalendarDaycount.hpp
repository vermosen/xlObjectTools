/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_daycount
#define xl_calendar_daycount

#include <ohxl/repositoryxl.hpp>

#include <ql/time/daycounter.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

        /*Fonction de calcul des daycount basis*/
DLLEXPORT double xlCalendarDaycount (double * calculationDate_, 
                                     double * endDate_,
                                     char * daycountBasis_) ;

#endif
