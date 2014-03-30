/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_roll_down
#define xl_swap_roll_down

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/yieldtermstructures.hpp>

#include <ohxl/conversions/scalartooper.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

#include <ql/termStructures/yield/translatedTermStructure.hpp>
#include <ql/pricingengines/swap/discountingswapengine.hpp>
#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>

#include <bot/swap/activeSwap.hpp>


        /* Fonction de calcul du roll-down d'un swap */
DLLEXPORT xloper * xlSwapRollDown (const char * instrumentId_,
                                   const char * discountCurveId_,
                                   xloper * forwardCurveId_,
                                   const double * fwdDate_,
								   xloper * trigger_) ;


#endif