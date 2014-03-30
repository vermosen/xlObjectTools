/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_bu_bill
#define xl_initiate_bu_bill

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/instruments/bond/buBill/buBillObject.hpp>

#include <bot/instruments/bond/buBill/buBillValueObject.hpp>

    /* enregistre un buBill */
DLLEXPORT xloper * xlInitiateBuBill (const char * objectID_,
                                     const double * issueDate_,
                                     const double * maturityDate_,
                                     xloper * trigger_) ;

#endif
