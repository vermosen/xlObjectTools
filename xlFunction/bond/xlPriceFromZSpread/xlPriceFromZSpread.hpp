/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_price_from_z_spread
#define xl_price_from_z_spread

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

        /*Fonction de calcul du prix à partir du spread spécifique */
DLLEXPORT xloper * xlPriceFromZSpread (const char * instrumentId_,
                                       const char * curveId_,
                                       xloper * zSpread_,
                                       xloper * conventionId_,
                                       xloper * settlementDate_,
                                       xloper * trigger_) ;

#endif
