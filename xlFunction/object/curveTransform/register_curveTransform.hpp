/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 23/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_curve_transform_hpp
#define register_curve_transform_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/curveTransform/xlInitiateCurveShift/register_xlInitiateCurveShift.hpp>

inline void register_curveTransform(const XLOPER & xDll) {
    

                    // register curve

            registerxlInitiateCurveShift(xDll) ;


    } ;

inline void unregister_curveTransform(const XLOPER & xDll) {
    

                    // unregister curve
            unregisterxlInitiateCurveShift(xDll) ;

    
    } ;


#endif