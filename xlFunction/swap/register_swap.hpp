/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_swap_hpp
#define register_swap_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/swap/xlSwapFairFixedRate/register_xlSwapFairFixedRate.hpp>

#include <xlFunction/swap/xlSwapAccruedAmount/register_xlSwapAccruedAmount.hpp>

#include <xlFunction/swap/xlSwapNPV/register_xlSwapNPV.hpp>

#include <xlFunction/swap/xlSwapRollDown/register_xlSwapRollDown.hpp>

#include <xlFunction/swap/xlSwapFlowsNPV/register_xlSwapFlowsNPV.hpp>

#include <xlFunction/swap/xlSwapDV01/register_xlSwapDV01.hpp>

#include <xlFunction/swap/xlSwapConvexity/register_xlSwapConvexity.hpp>

#include <xlFunction/swap/xlSwapCurrentFixing/register_xlSwapCurrentFixing.hpp>

inline void register_swap(const XLOPER & xDll) {
    

                // register swap
        registerxlSwapFairFixedRate(xDll) ;

        registerxlSwapAccruedAmount(xDll) ;

        registerxlSwapNPV(xDll) ;

		registerxlSwapRollDown(xDll) ;

		registerxlSwapFlowsNPV(xDll) ;

		registerxlSwapDV01(xDll) ;

		registerxlSwapCurrentFixing(xDll) ;

		//registerxlSwapConvexity(xDll) ;

    } ;

inline void unregister_swap(const XLOPER & xDll) {
    

            // unregister swap
        unregisterxlSwapFairFixedRate(xDll) ;

        unregisterxlSwapAccruedAmount(xDll) ;

        unregisterxlSwapNPV(xDll) ;

		unregisterxlSwapRollDown(xDll) ;

		unregisterxlSwapFlowsNPV(xDll) ;

		unregisterxlSwapDV01(xDll) ;

		unregisterxlSwapCurrentFixing(xDll) ;

		//unregisterxlSwapConvexity(xDll) ;

    } ;


#endif