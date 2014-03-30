/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_future_deposit_bootstrap__helper
#define xl_initiate_future_deposit_bootstrap__helper

#include <ohxl/convert_oper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/curve/bootstrapHelper/depositFutureBootstrapHelper/depositFutureBootstrapHelperObject.hpp>

#include <bot/index/iborIndex/iborIndexObject.hpp>


        /* enregistre un helper pour un future sur dépot */
DLLEXPORT xloper * xlInitiateDepositFutureBootstrapHelper (const char * objectId_,
														   const char * immCode_,
														   const char * iborIndex_,
                                                           const double * depositQuote_,
														   const xloper * convexityAdjustmentQuote_,
														   const xloper * meanRevertingQuote_,
                                                           const xloper * trigger_) ;

#endif
