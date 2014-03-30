/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_interest_rate
#define xl_initiate_interest_rate

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/factory/compounding/compoundingFactory.hpp>

#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* enregistre une convention de cotation */
DLLEXPORT xloper * xlInitiateInterestRate (const char * objectID_,
                                           const char * accrualID_,
                                           const char * compoundingID_,
                                           const char * frequencyID_,
                                           const char * businessDayConventionID_,
                                           xloper * trigger_) ;

#endif
