/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_daycount
#define xl_calendar_daycount

#include <ql/time/daycounter.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

#include <ohxl/conversions/scalartooper.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

// calculates the corresponding daycount basis
DLLEXPORT xloper * xlCalendarDaycount(double * calculationDate_,
                                      double * endDate_,
                                      char * daycountBasis_) ;

#endif
