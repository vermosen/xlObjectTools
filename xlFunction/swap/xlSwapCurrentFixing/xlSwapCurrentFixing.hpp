/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_swap_current_fixing
#define xl_swap_current_fixing

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/convert_oper.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <ql/cashflows/cashflows.hpp>


#include <qlo/conversions/coercehandle.hpp>

#include <qlo/yieldtermstructures.hpp>


#include <bot/swap/activeSwap.hpp>

#include <bot/leg/activeLeg.hpp>


        /* Fonction de calcul de l'accrued d'un swap ou d'une jambe */
DLLEXPORT xloper * xlSwapCurrentFixing (const char * instrumentId_,
                                        const double * settlementDate_,
                                        xloper * referenceIndex_,
                                        xloper * trigger_) ;

#endif