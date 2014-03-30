/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_aussie_bill
#define xl_initiate_aussie_bill

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/instruments/bond/aussieBill/aussieBillObject.hpp>

#include <bot/instruments/bond/aussieBill/aussieBillValueObject.hpp>

    /* enregistre un aussieBill */
DLLEXPORT xloper * xlInitiateAussieBill (const char * objectID_,
                                         const double * issueDate_,
                                         const double * maturityDate_,
                                         const xloper * settlementDays_,
                                         const xloper * trigger_) ;

#endif