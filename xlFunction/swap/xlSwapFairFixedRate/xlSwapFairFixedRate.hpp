    /*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_fair_fixed_rate
#define xl_swap_fair_fixed_rate

#include <qlo/yieldtermstructures.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ql/pricingengines/swap/discountingswapengine.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

#include <bot/swap/activeSwap.hpp>

        /* Fonction de calcul du fair rate d'un swap
           le principe est le suivant : on identifie 
           la jambe fixe du swap qu'il s'agit d'ajuster.
           En seconde étape, on calcule la NPV du swap 
           sans cette jambe. Enfin, on effectue le calcul
           du fair rate */
DLLEXPORT xloper * xlSwapFixedRate (const char * swapId_,
                                    const char * legId_,
                                    const char * curveId_,
                                    xloper * trigger_) ;

#endif