/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_deposit
#define xl_initiate_deposit

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/time/calendars/unitedstates.hpp>
#include <ql/instruments/bonds/deposit.hpp>

#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/currency/currencyFactory.hpp>
#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/instruments/deposit/depositObject.hpp>

        /* enregistre un depôt */
DLLEXPORT xloper * xlInitiateDeposit (const char * objectID_,
                                      const xloper * startDate_,
                                      const double * maturityDate_,
                                      const xloper * calendar_,
                                      const xloper * settlementDays_,
                                      const xloper * paymentConvention_,
                                      const xloper * endOfmonth_,
                                      const xloper * trigger_) ;

#endif
