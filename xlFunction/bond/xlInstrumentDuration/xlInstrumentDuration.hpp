/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_duration
#define xl_instrument_duration

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>

#include <bot/factory/duration/durationFactory.hpp>
#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul des différentes durations pour un intrument */
DLLEXPORT xloper * xlInstrumentDuration (const char * instrumentId_,
                                         xloper * npvDate_,
                                         xloper * settlementDate_,
                                         const double * instrumentCleanPrice_,
                                         xloper * durationType_,
                                         const char * conventionId_,
                                         xloper * trigger_) ;

#endif