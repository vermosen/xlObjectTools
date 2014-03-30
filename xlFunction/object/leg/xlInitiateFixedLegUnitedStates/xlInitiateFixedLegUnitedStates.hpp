/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_fixed_leg_united_states
#define xl_initiate_fixed_leg_united_states

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/leg/fixedLegUnitedStates/fixedLegUnitedStatesObject.hpp>

        /* enregistre une jambe de swap fixe libélée en dollar */
DLLEXPORT xloper * xlInitiateFixedLegUnitedStates (const char * objectID_,
                                                   const double * effectiveDate_,
                                                   const xloper * firstCouponDate_,
                                                   const xloper * lastCouponDate_,
                                                   const double * maturityDate_,
                                                   const xloper * notional_,
                                                   const double * couponRate_,
                                                   const xloper * frequency_,
                                                   const xloper * daycounter_,
                                                   xloper * trigger_) ;

#endif
