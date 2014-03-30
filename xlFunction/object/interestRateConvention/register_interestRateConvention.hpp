/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_interest_rate_convention_hpp
#define register_interest_rate_convention_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/interestRateConvention/xlInitiateInterestRate/register_xlInitiateInterestRate.hpp>

inline void register_interestRateConvention(const XLOPER & xDll) {
    

                    // register convention
            registerxlInitiateInterestRate(xDll) ;
   
    
    } ;

inline void unregister_interestRateConvention(const XLOPER & xDll) {
    

                    // unregister convention
            unregisterxlInitiateInterestRate(xDll) ;
   
    
    } ;


#endif
