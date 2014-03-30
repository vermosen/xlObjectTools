/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_fixed_leg_australia
#define xl_initiate_fixed_leg_australia

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/leg/fixedLegAustralia/fixedLegAustraliaObject.hpp>

        /* enregistre une jambe fixe en AUD */
DLLEXPORT xloper * xlInitiateFixedLegAustralia (const char * objectID_,
                                                const double * effectiveDate_,
                                                xloper * firstCouponDate_,
                                                xloper * lastCouponDate_,
                                                const double * maturityDate_,
                                                xloper * notional_,
                                                const double * couponRate_,
                                                xloper * frequency_,
                                                xloper * daycounter_,
                                                xloper * trigger_) ;

#endif
