/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_zero_coupon_inflation_swap_united_states
#define xl_initiate_zero_coupon_inflation_swap_united_states

#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <bot/index/inflationIndex/inflationIndexObject.hpp>

#include <bot/swap/zeroCouponInflationSwapUnitedStates/zeroCouponInflationSwapUnitedStatesObject.hpp>

        /* enregistre un swap inflation */
DLLEXPORT xloper * xlInitiateZeroCouponInflationSwapUnitedStates (const char * objectID_,
                                                                  const char * fixedLegId_,
                                                                  const char * inflationLegId_,
                                                                  const bool payFixed_,
                                                                  xloper * trigger_) ;

#endif
