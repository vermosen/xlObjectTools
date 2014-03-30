/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_carry
#define xl_instrument_carry

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ohxl/conversions/scalartooper.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

#include <ql/termstructures/yield/flatforward.hpp>
#include <ql/pricingengines/bond/discountingbondengine.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul du time value de l'instrument */
DLLEXPORT xloper * xlInstrumentCarry (const char * instrumentId_,
                                      const double * startAccruedDate_,
                                      const double * endAccruedDate_,
                                      const double * instrumentYield_,
                                      const char * conventionId_,
                                      xloper * trigger_) ;

#endif