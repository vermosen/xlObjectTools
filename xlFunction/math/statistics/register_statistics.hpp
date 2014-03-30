/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_statistics_hpp
#define register_statistics_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/math/statistics/xlKalmanFilter/register_xlKalmanFilter.hpp>


inline void register_statistics(const XLOPER & xDll) {
    

                    // register math
            registerxlKalmanFilter(xDll) ;

   
    
    } ;

inline void unregister_statistics(const XLOPER & xDll) {


                    // unregister math
            unregisterxlKalmanFilter(xDll) ;

   
    
    } ;


#endif
