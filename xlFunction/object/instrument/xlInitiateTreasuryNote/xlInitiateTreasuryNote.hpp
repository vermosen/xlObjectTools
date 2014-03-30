/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_tnote
#define xl_initiate_tnote

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/instruments/bond/treasuryNote/treasuryNoteObject.hpp>

        /* enregistre un TNote */
DLLEXPORT xloper * xlInitiateTreasuryNote (const char * objectID_,
                                           const double * issueDate_,
                                           const double * effectiveDate_,
                                           const double * firstCouponDate_,
                                           const double * lastCouponDate_,
                                           const double * maturityDate_,
                                           const double * couponRate_,
                                           xloper * trigger_) ;

#endif
