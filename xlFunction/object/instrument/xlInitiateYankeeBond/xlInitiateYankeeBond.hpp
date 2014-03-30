/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_yankee_bond
#define xl_initiate_yankee_bond

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/instruments/bond/yankeeBond/yankeeBondObject.hpp>

        /* enregistre un titre yankee */
DLLEXPORT xloper * xlInitiateYankeeBond (const char * objectID_,
                                         const double * issueDate_,
                                         const double * effectiveDate_,
                                         const double * firstCouponDate_,
                                         const double * lastCouponDate_,
                                         const double * maturityDate_,
                                         const double * couponRate_,
                                         const double * frequency_,
                                         const char * daycounter_,
                                         const double * settleDays_,
                                         const bool * endOfMonth_,
                                         xloper * trigger_) ;

#endif
