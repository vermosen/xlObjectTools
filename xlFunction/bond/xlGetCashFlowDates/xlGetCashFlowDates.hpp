/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_get_cash_flow_dates
#define xl_get_cash_flow_dates

#include <ql/errors.hpp>

#include <qlo/bonds.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/vectortoOper.hpp>

        /* fonction de récupération des dates de paiement d'un instrument */
DLLEXPORT xloper * xlGetCashFlowDates (const char * objectID_,
                                       xloper * trigger_) ;

#endif
