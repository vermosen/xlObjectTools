/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_settlement_date
#define xl_instrument_settlement_date

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/instruments/activeInstrument.hpp>

#include <bot/swap/activeSwap.hpp>

        /* fournit la date de règlement de l'instrument */
DLLEXPORT xloper * xlInstrumentSettlementDate (const char * instrumentId_,
                                               xloper * evaluationDate_,
                                               xloper * trigger_) ;

#endif