/*
*  xlObjectTools
*
*  Created by Jean-Matthieu VERMOSEN on 31/05/09
*  Copyright 2009. All rights reserved.
*
*/

#ifndef xl_retrieve_error
#define xl_retrieve_error

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/errors.hpp>
#include <ql/settings.hpp>

// retrieve the current error associated to a range
DLLEXPORT xloper * xlRetrieveError(xloper * range_,
								   xloper * trigger_);

#endif