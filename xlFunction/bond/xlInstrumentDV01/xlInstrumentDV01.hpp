/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_dv01
#define xl_instrument_dv01

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul des différentes durations pour un intrument */
DLLEXPORT xloper * xlInstrumentDV01 (const char * instrumentId_,
                                     xloper * npvDate_,
                                     xloper * settlementDate_,
                                     const double * instrumentCleanPrice_,
                                     const char * conventionId_,
                                     xloper * trigger_) ;

#endif