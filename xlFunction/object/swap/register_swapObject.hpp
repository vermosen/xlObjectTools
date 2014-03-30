/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_swap_object_hpp
#define register_swap_object_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/swap/xlInitiateInterestRateSwap/register_xlInitiateInterestRateSwap.hpp>

inline void register_swapObject(const XLOPER & xDll) {

                    // register swap
            registerxlInitiateInterestRateSwap(xDll) ;         

    } ;

inline void unregister_swapObject(const XLOPER & xDll) {

                    // unregister swapObject
            registerxlInitiateInterestRateSwap(xDll) ;
    
    } ;

#endif