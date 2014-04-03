/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_aussie_note
#define xl_initiate_aussie_note

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/instruments/bond/australianTreasuryNote/australianTreasuryNoteObject.hpp>
#include <bot/instruments/bond/australianTreasuryNote/australianTreasuryNoteValueObject.hpp>

    /* enregistre un aussieNote */
DLLEXPORT xloper * xlInitiateAussieNote (const char * objectID_,
                                         const double * issueDate_,
                                         xloper * effectiveDate_,
                                         xloper * firstCouponDate_,
                                         xloper * lastCouponDate_,
                                         const double * maturityDate_,
                                         const double * couponRate_,
                                         xloper * trigger_) ;

#endif
