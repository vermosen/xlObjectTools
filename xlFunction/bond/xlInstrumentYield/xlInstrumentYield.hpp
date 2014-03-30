/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_yield
#define xl_instrument_yield

#include <qlo/conversions/coercehandle.hpp>


#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/instruments/activeInstrument.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul du yield bond basis d'un instrument */
DLLEXPORT xloper * xlInstrumentYield (const char * instrumentId_,
                                      const double * price_,
                                      xloper * settlementDate_,
                                      const char * conventionId_,
                                      xloper * trigger_) ;

#endif