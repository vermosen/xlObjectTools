/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_leg_hpp
#define register_leg_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/leg/xlInitiateFloatLegUnitedStates/register_xlInitiateFloatLegUnitedStates.hpp>

#include <xlFunction/object/leg/xlInitiateFixedLegUnitedStates/register_xlInitiateFixedLegUnitedStates.hpp>

#include <xlFunction/object/leg/xlInitiateFixedLegAustralia/register_xlInitiateFixedLegAustralia.hpp>

#include <xlFunction/object/leg/xlInitiateFloatLegAustralia/register_xlInitiateFloatLegAustralia.hpp>


inline void register_leg(const XLOPER & xDll) {
    

                // register leg
            registerxlInitiateFloatLegUnitedStates(xDll) ;

            registerxlInitiateFixedLegUnitedStates(xDll) ;

            registerxlInitiateFloatLegAustralia(xDll) ;

            registerxlInitiateFixedLegAustralia(xDll) ;
   
    
    } ;

inline void unregister_leg(const XLOPER & xDll) {
    

                // unregister leg
            unregisterxlInitiateFloatLegUnitedStates(xDll) ;

            unregisterxlInitiateFixedLegUnitedStates(xDll) ;

            unregisterxlInitiateFloatLegAustralia(xDll) ;

            unregisterxlInitiateFixedLegAustralia(xDll) ;
   
    
    } ;


#endif
