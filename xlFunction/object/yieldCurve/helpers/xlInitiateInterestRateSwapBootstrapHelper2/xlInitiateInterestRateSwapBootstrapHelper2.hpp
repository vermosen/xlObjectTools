/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_interest_rate_swap_bootstrap_helper2
#define xl_initiate_interest_rate_swap_bootstrap_helper2


#include <ohxl/convert_oper.hpp>
#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/frequency/frequencyFactory.hpp>
#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/factory/daycounter/daycountFactory.hpp>
#include <bot/factory/period/periodFactory.hpp>
#include <bot/index/iborIndex/iborIndexObject.hpp>
#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper2/interestRateSwapBootstrapHelperObject2.hpp>

#include <qlo/termstructures.hpp>



        /* enregistre un helper pour un swap */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper2 (const char * objectId_,
															   const char * tenor_,
															   const char * calendar_,
															   const xloper * settlementDays_,
                                                               const xloper * fixedFrequency_,
                                                               const xloper * fixedDayCount_,
															   const double * fixedRate_,
															   const xloper * floatFrequency_,
                                                               const xloper * floatDayCount_,
															   const char * floatIndex_,
															   const xloper * dicountCurve_,
                                                               const xloper * trigger_) ;


#endif
