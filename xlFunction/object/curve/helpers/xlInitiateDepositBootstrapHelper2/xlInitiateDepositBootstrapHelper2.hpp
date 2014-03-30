/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_deposit_bootstrap_helper_2
#define xl_initiate_deposit_bootstrap_helper_2


#include <ohxl/convert_oper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/calendar/calendarFactory.hpp>

#include <bot/factory/period/periodFactory.hpp>

#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>


#include <bot/instruments/deposit/depositObject.hpp>

#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperObject.hpp>


#include <ql/time/calendars/unitedstates.hpp>

#include <ql/handle.hpp>



        /* enregistre un helper pour un dépôt */
DLLEXPORT xloper * xlInitiateDepositBootstrapHelper2 (const char * objectId_,
                                                      const char * tenor_,
													  const xloper * calendar_,
													  const xloper * settlementDays_,
                                                      const double * depositRate_,
													  const xloper * annualBasis_,
                                                      const xloper * trigger_) ;


#endif
