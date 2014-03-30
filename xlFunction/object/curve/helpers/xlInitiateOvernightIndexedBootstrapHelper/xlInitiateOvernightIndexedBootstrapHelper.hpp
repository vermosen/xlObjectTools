/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
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

#include <bot/curve/bootstrapHelper/overnightIndexedSwapBootstrapHelper/overnightIndexedSwapBootstrapHelperObject.hpp>

#include <bot/index/overnightIndex/overnightIndexObject.hpp>


#include <ql/time/calendars/unitedstates.hpp>

#include <ql/handle.hpp>


        /* enregistre un helper pour un swap OIS */
DLLEXPORT xloper * xlInitiateOvernightIndexedBootstrapHelper (const char * objectId_,
                                                              const char * indexId_,
															  const double * maturityDate_,
                                                              const double * swapQuote_,
                                                              const xloper * trigger_) ;


#endif
