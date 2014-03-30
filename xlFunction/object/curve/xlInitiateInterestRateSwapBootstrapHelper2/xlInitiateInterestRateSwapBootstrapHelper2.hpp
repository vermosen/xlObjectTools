/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#ifndef xl_initiate_interest_rate_swap_bootstrap_helper2
#define xl_initiate_interest_rate_swap_bootstrap_helper2


#include <ohxl/convert_oper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/instruments/deposit/depositObject.hpp>

#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperObject.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>

#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>

#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper/interestRateSwapBootstrapHelperObject.hpp>


        /* enregistre un helper pour un swap */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper2 (const char * objectId_,
															   const double * maturityDate_,
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
