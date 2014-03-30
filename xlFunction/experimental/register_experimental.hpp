/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_experimental_hpp
#define register_experimental_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/experimental/xlEfficientConstrainedFrontier/register_xlEfficientConstrainedFrontier.hpp>

//#include <xlFunction/experimental/xlInitiateFittedBondDiscountCurve/register_xlInitiateFittedBondDiscountCurve.hpp>

#include <xlFunction/experimental/xlInitiateSwapCurve/register_xlInitiateSwapCurve.hpp>


inline void register_experimental(const XLOPER & xDll) {
    

                    // register experimental
            registerxlEfficientConstrainedFrontier(xDll) ;

            //registerxlInitiateFittedBondDiscountCurve(xDll) ;

            registerxlInitiateSwapCurve(xDll) ;
   
    
    } ;

inline void unregister_experimental(const XLOPER & xDll) {


                    // unregister experimental
            unregisterxlEfficientConstrainedFrontier(xDll) ;

            //unregisterxlInitiateFittedBondDiscountCurve(xDll) ;

            unregisterxlInitiateSwapCurve(xDll) ;
   
    
    } ;


#endif
