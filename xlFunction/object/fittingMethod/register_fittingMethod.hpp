/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 23/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_fitting_method_hpp

#define register_fitting_method_hpp


#include <xlsdk/xlsdkdefines.hpp>


#include <xlFunction/object/fittingMethod/xlInitiateSvenssonModel/register_xlInitiateSvenssonModel.hpp>

#include <xlFunction/object/fittingMethod/xlInitiateNelsonSiegelModel/register_xlInitiateNelsonSiegelModel.hpp>


inline void register_fittingMethod(const XLOPER & xDll) {


                // register fitting method
            registerxlInitiateSvenssonModel (xDll) ;

            registerxlInitiateNelsonSiegelModel (xDll) ;


    } ;

inline void unregister_fittingMethod(const XLOPER & xDll) {


                // unregister fitting method
            unregisterxlInitiateSvenssonModel (xDll) ;

            unregisterxlInitiateNelsonSiegelModel (xDll) ;


    } ;


#endif