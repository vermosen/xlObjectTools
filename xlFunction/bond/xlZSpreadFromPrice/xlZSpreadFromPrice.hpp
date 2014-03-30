/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_z_spread_from_price
#define xl_z_spread_from_price

#include <qlo/yieldtermstructures.hpp>
#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /*Fonction de calcul du z-spread conventionnel à partir du prix */
DLLEXPORT xloper * xlZSpreadFromPrice (const char * instrumentId_,
                                       const char * curveId_,
                                       const double * price_,
                                       xloper * conventionId_,
                                       xloper * settlementDate_,
                                       xloper * trigger_) ;

#endif
