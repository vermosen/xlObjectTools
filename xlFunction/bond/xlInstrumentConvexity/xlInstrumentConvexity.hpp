/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_convexity
#define xl_instrument_convexity

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/bonds.hpp>

#include <ql/instruments/bond.hpp>
#include <ql/pricingengines/bond/bondfunctions.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul de la convexité de l'instrument */
DLLEXPORT xloper * xlInstrumentConvexity (const char * instrumentId_,
                                          const xloper * npvDate_,
                                          const xloper * settlementDate_,
                                          const double * instrumentCleanPrice_,
                                          const char * conventionId_,
                                          const xloper * trigger_) ;

#endif