/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_kangaroo_bond
#define xl_initiate_kangaroo_bond

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/daycounter/daycountFactory.hpp>

#include <bot/factory/frequency/frequencyFactory.hpp>

#include <bot/instruments/bond/kangarooBond/kangarooBondObject.hpp>

        /* enregistre un titre kangaroo */
DLLEXPORT xloper * xlInitiateKangarooBond (const char * objectID_,
                                           const double * issueDate_,
                                           const xloper * effectiveDate_,
                                           const xloper * firstCouponDate_,
                                           const xloper * lastCouponDate_,
                                           const double * maturityDate_,
                                           const double * couponRate_,
                                           const xloper * frequency_,
                                           const xloper * daycounter_,
                                           const xloper * settleDays_,
                                           const xloper * endOfMonth_,
                                           const xloper * exDividendDays_,
                                           const xloper * trigger_) ;

#endif
