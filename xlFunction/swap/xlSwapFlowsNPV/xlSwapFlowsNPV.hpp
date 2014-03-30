/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_flows_npv
#define xl_swap_flows_npv

#include <ohxl/repositoryxl.hpp>

#include <qlo/yieldtermstructures.hpp>

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/vectortoOper.hpp>

#include <ql/cashflow.hpp>

#include <bot/leg/activeLeg.hpp>

#include <bot/swap/activeSwap.hpp>

        /* fonction de récupération des flux actualisés d'un instrument */
DLLEXPORT xloper * xlSwapFlowsNPV (const char * objectID_,
								   const char * curveID_,
                                   xloper * trigger_) ;

#endif
