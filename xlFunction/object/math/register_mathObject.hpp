/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_math_object_hpp
#define register_math_object_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/math/xlInitiateMatrix/register_xlInitiateMatrix.hpp>
#include <xlFunction/object/math/xlInitiateTimeSeries/register_xlInitiateTimeSeries.hpp>

inline void register_mathObject(const XLOPER & xDll) {
    
                // register object math functions
            registerxlInitiateMatrix(xDll) ;
            registerxlInitiateTimeSeries(xDll) ;
    
    } ;

inline void unregister_mathObject(const XLOPER & xDll) {
    
                // unregister object math functions
            unregisterxlInitiateMatrix(xDll) ;
            unregisterxlInitiateTimeSeries(xDll) ;
    
    } ;

#endif
