/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_object_hpp
#define register_object_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/yieldCurve/register_curveObject.hpp>

#include <xlFunction/object/interestRateConvention/register_interestRateConvention.hpp>

#include <xlFunction/object/curveTransform/register_curveTransform.hpp>

#include <xlFunction/object/instrument/register_instrument.hpp>

#include <xlFunction/object/math/register_mathObject.hpp>

#include <xlFunction/object/index/register_index.hpp>

#include <xlFunction/object/swap/register_swapObject.hpp>

#include <xlFunction/object/fittingMethod/register_fittingMethod.hpp>

#include <xlFunction/object/leg/register_leg.hpp>

inline void register_object(const XLOPER & xDll) {


                    // register objects
            register_leg(xDll) ;
            
			register_instrument(xDll) ;
            
			register_index(xDll) ;
            
			register_curve(xDll) ;
            
			register_mathObject(xDll) ;
            
			register_interestRateConvention(xDll) ;

			register_curveTransform(xDll) ;

			register_swapObject(xDll) ;

            register_fittingMethod(xDll) ;

    
    } ;

inline void unregister_object(const XLOPER & xDll) {
    

                    // unregister objects
            unregister_leg(xDll) ;
            
			unregister_instrument(xDll) ;
            
			unregister_index(xDll) ;
            
			unregister_curve(xDll) ;
            
			unregister_mathObject(xDll) ;
            
			unregister_interestRateConvention(xDll) ;
			
			unregister_curveTransform(xDll) ;

			unregister_swapObject(xDll) ;

            unregister_fittingMethod(xDll) ;

    
    } ;


#endif