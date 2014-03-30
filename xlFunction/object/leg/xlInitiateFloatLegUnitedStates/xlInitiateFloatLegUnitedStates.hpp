/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_float_leg_united_states
#define xl_initiate_float_leg_united_states

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <ql/indexes/iborindex.hpp>


#include <bot/index/iborIndex/iborIndexObject.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/leg/floatLegUnitedStates/floatLegUnitedStatesObject.hpp>

        /* enregistre une jambe à taux variable */
DLLEXPORT xloper * xlInitiateFloatLegUnitedStates (const char * objectID_,
                                                   const double * effectiveDate_,
                                                   xloper * firstCouponDate_,
                                                   xloper * lastCouponDate_,
                                                   const double * maturityDate_,
                                                   xloper * notional_,
                                                   const char * indexId_,
                                                   xloper * frequency_,
                                                   xloper * daycounter_,
                                                   xloper * spread_,
                                                   xloper * trigger_) ;

#endif
