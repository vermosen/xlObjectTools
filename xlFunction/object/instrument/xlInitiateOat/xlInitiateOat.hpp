/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_bu_note
#define xl_initiate_bu_note

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/instruments/bond/oat/oatObject.hpp>

#include <bot/instruments/bond/oat/oatValueObject.hpp>

    /* enregistre un buNote */
DLLEXPORT xloper * xlInitiateOat (const char * objectID_,
                                  const double * issueDate_,
                                  const double * effectiveDate_,
                                  const double * firstCouponDate_,
                                  const double * lastCouponDate_,
                                  const double * maturityDate_,
                                  const double * couponRate_,
                                  xloper * trigger_) ;

#endif
