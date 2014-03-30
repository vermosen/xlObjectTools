/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 23/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_index_hpp
#define register_index_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/index/xlInitiateOvernightIndex/register_xlInitiateOvernightIndex.hpp>

#include <xlFunction/object/index/xlInitiateIborIndex/register_xlInitiateIborIndex.hpp>

inline void register_index(const XLOPER & xDll) {
    

                    // register index
            registerxlInitiateIborIndex(xDll) ;
            
            registerxlInitiateOvernightIndex(xDll) ;

    
    } ;

inline void unregister_index(const XLOPER & xDll) {
    

                    // unregister index
            unregisterxlInitiateIborIndex(xDll) ;
   
            unregisterxlInitiateOvernightIndex(xDll) ;


    } ;


#endif