/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 23/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_volatility_surface_object_hpp
#define register_volatility_surface_object_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/volatilitySurface/helpers/xlInitiateSwaptionHelper/register_xlInitiateSwaptionHelper.hpp>

inline void register_volatilitySurface(const XLOPER & xDll) {

		registerxlInitiateSwaptionHelper(xDll);
            
    } ;

inline void unregister_volatilitySurface(const XLOPER & xDll) {
			
		unregisterxlInitiateSwaptionHelper(xDll);

    } ;

#endif