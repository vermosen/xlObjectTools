/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_pricing_date
#define xl_pricing_date

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/errors.hpp>
#include <ql/settings.hpp>

        /* permet de fixer/récupérer la date de pricing */
DLLEXPORT double xlPricingDate (xloper * date_,
                                xloper * trigger_) ;

#endif