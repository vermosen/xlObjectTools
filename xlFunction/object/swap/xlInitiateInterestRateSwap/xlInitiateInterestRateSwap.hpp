/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_interest_rate_swap
#define xl_initiate_interest_rate_swap


#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <qlo/couponvectors.hpp>


#include <bot/swap/interestRateSwap/interestRateSwapObject.hpp>


        /* enregistre un IRS */
DLLEXPORT xloper * xlInitiateInterestRateSwap (const char * objectID_,
                                               char * fixedLegId_,
                                               char * floatLegId_,
                                               bool * payFixed_,
                                               xloper * trigger_) ;

#endif
