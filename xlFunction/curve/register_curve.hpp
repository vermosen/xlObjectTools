/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_curve_hpp
#define register_curve_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/curve/xlCurveForwardRate/register_xlCurveForwardRate.hpp>

#include <xlFunction/curve/xlCurveZeroRate/register_xlCurveZeroRate.hpp>

#include <xlFunction/curve/xlCurveReferenceDate/register_xlCurveReferenceDate.hpp>

#include <xlFunction/curve/xlFittingRSquare/register_xlFittingRSquare.hpp>

#include <xlFunction/curve/xlRecoverFittingParameters/register_xlRecoverFittingParameters.hpp>


inline void register_yieldCurve(const XLOPER & xDll) {


                // register yield curve functions
            registerxlCurveForwardRate(xDll) ;

            registerxlCurveZeroRate(xDll) ;

            registerxlCurveReferenceDate(xDll) ;

            registerxlFittingRSquare(xDll) ;

            registerxlRecoverFittingParameters(xDll) ;


    } ;

inline void unregister_yieldCurve(const XLOPER & xDll) {


                // unregister yield curve functions
            unregisterxlCurveForwardRate(xDll) ;

            unregisterxlCurveZeroRate(xDll) ;

            unregisterxlCurveReferenceDate(xDll) ;

            unregisterxlFittingRSquare(xDll) ;

            unregisterxlRecoverFittingParameters(xDll) ;


    } ;


#endif
