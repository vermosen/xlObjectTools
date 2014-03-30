/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_tbill
#define xl_initiate_tbill

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/instruments/bond/treasuryBill/treasuryBillObject.hpp>

        /* enregistre un treasuryBill */
DLLEXPORT char * xlInitiateTreasuryBill (const char * objectID_,
                                         const double * issueDate_,
                                         const double * maturityDate_,
                                         xloper * trigger_) ;

#endif
