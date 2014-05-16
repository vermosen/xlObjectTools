/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_addin_hpp
#define register_addin_hpp

#include <xlsdk/xlsdkdefines.hpp>
#include <xlFunction/addin/xlPricingDate/register_xlPricingDate.hpp>

inline void register_addin(const XLOPER & xDll) {

            // register addin functions
            registerxlPricingDate(xDll);
			// registerxlRetrieveError(xDll);
    
    } ;

inline void unregister_addin(const XLOPER & xDll) {

            // unregister addin functions
            unregisterxlPricingDate(xDll);
			// unregisterxlRetrieveError(xDll);

    } ;

#endif
