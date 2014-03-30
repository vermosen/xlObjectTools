/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_convexity
#define xl_swap_convexity

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ql/instruments/vanillaSwap2.hpp>

#include <bot/swap/activeSwap.hpp>
#include <bot/leg/activeLeg.hpp>

        /* calculation of the convexity of a swap or leg */
DLLEXPORT xloper * xlSwapConvexity (const char * instrumentId_,
                                    const char * curveId_,
                                    xloper * trigger_) ;

#endif