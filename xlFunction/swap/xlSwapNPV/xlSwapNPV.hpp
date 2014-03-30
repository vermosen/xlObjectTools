/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_npv
#define xl_swap_npv

#include <ql/pricingengines/swap/discountingswapengine.hpp>

#include <qlo/yieldtermstructures.hpp>
#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/swap/activeSwap.hpp>

        /* Fonction de calcul de la NPV d'un swap ou d'une jambe */
DLLEXPORT xloper * xlSwapNPV (const char * instrumentId_,
                              const char * discountCurveId_,
                              xloper * forwardCurveId_,
                              xloper * trigger_) ;

#endif