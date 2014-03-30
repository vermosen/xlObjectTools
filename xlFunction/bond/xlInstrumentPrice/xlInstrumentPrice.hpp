/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_price
#define xl_instrument_price

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <qlo/conversions/coercehandle.hpp>


#include <bot/instruments/activeInstrument.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

            /* Fonction de conversion yield -> prix pour les T-note et T-Bill*/
DLLEXPORT xloper * xlInstrumentPrice (const char * instrumentId_,
                                      xloper * settlementDate_,
                                      const double * yield_,
                                      xloper * conventionId_, 
                                      xloper * trigger_) ;

#endif
