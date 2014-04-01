/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_interest_rate_swap_bootstrap_helper
#define xl_initiate_interest_rate_swap_bootstrap_helper

#include <ohxl/convert_oper.hpp>
#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/instruments/deposit/depositObject.hpp>
#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperObject.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper/interestRateSwapBootstrapHelperObject.hpp>

#include <ql/instruments/vanillaSwap2.hpp>

#include <qlo/termstructures.hpp>

        /* enregistre un helper pour un swap */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper (const char * objectID_,
                                                              const char * swapId_,
                                                              const double * quote_,
                                                              const xloper * discountCurve_,
                                                              const xloper * trigger_) ;

#endif
