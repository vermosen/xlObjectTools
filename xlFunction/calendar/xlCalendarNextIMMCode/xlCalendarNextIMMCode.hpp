/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_calendar_next_imm_code
#define xl_calendar_next_imm_code

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/time/imm.hpp>
#include <ql/errors.hpp>

	// Computes the next IMM code
DLLEXPORT char * xlCalendarNextIMMCode (xloper * calculationDate_) ;

#endif
