/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_imm_date
#define xl_calendar_imm_date

#include <ql/time/imm.hpp>
#include <ql/errors.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

	// compute the date corresponding to the IMM code
DLLEXPORT double xlCalendarIMMDate (xloper * calculationDate_,
                                    char * immCode_) ;

#endif
