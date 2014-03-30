/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#ifndef xl_initiate_deposit_bootstrap_helper
#define xl_initiate_deposit_bootstrap_helper


#include <ohxl/convert_oper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/calendar/calendarFactory.hpp>

#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>

#include <bot/instruments/deposit/depositObject.hpp>

#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperObject.hpp>


#include <ql/time/calendars/unitedstates.hpp>

#include <ql/handle.hpp>



        /* enregistre un helper pour un dépôt */
DLLEXPORT xloper * xlInitiateDepositBootstrapHelper (const char * objectId_,
                                                     const char * depositId_,
                                                     const double * depositPrice_,
                                                     const xloper * trigger_) ;


#endif
