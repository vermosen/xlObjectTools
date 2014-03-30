/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_dv01
#define xl_swap_dv01

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <ql/instruments/vanillaSwap2.hpp>
#include <ql/pricingengines/swap/discountingswapengine.hpp>
#include <ql/termstructures/yield/zerospreadedtermstructure.hpp>
#include <ql/quotes/simplequote.hpp>

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/yieldtermstructures.hpp>

#include <bot/swap/activeSwap.hpp>
#include <bot/leg/activeLeg.hpp>
#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

        /* Fonction de calcul de l'accrued d'un swap ou d'une jambe */
DLLEXPORT xloper * xlSwapDV01 (const char * instrumentId_,
                               const char * curveId_,
                               const char * conventionId_,
                               xloper * trigger_) ;

#endif