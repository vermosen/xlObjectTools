/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 23/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_curve_object_hpp

#define register_curve_object_hpp


#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/object/curve/xlInitiateSwapCurveUnitedStates/register_xlInitiateSwapCurveUnitedStates.hpp>
#include <xlFunction/object/curve/xlInitiateShiftedCurve/register_xlInitiateShiftedCurve.hpp>
#include <xlFunction/object/curve/xlInitiateFittedBondDiscountCurve/register_xlInitiateFittedBondDiscountCurve.hpp>
#include <xlFunction/object/curve/xlInitiateSwapCurveAustralia/register_xlInitiateSwapCurveAustralia.hpp>
#include <xlFunction/object/curve/xlInitiateInterpolatedCurve/register_xlInitiateInterpolatedCurve.hpp>

#include <xlFunction/object/curve/helpers/xlInitiateDepositBootstrapHelper/register_xlInitiateDepositBootstrapHelper.hpp>
#include <xlFunction/object/curve/helpers/xlInitiateDepositBootstrapHelper2/register_xlInitiateDepositBootstrapHelper2.hpp>
#include <xlFunction/object/curve/helpers/xlInitiateDepositFutureBootstrapHelper/register_xlInitiateDepositFutureBootstrapHelper.hpp>
#include <xlFunction/object/curve/helpers/xlInitiateInterestRateSwapBootstrapHelper/register_xlInitiateInterestRateSwapBootstrapHelper.hpp>
#include <xlFunction/object/curve/helpers/xlInitiateInterestRateSwapBootstrapHelper2/register_xlInitiateInterestRateSwapBootstrapHelper2.hpp>
#include <xlFunction/object/curve/helpers/xlInitiateOvernightIndexedBootstrapHelper/register_xlInitiateOvernightIndexedBootstrapHelper.hpp>

inline void register_curve(const XLOPER & xDll) {

            /**/
			registerxlInitiateSwapCurveUnitedStates(xDll) ;
            registerxlInitiateSwapCurveAustralia(xDll) ;
            /**/

			registerxlInitiateShiftedCurve(xDll) ;
            registerxlInitiateFittedBondDiscountCurve(xDll) ;
            registerxlInitiateDepositBootstrapHelper(xDll) ;
			registerxlInitiateDepositBootstrapHelper2(xDll) ;
			registerxlInitiateDepositFutureBootstrapHelper(xDll) ;
            registerxlInitiateInterestRateSwapBootstrapHelper(xDll) ;
			registerxlInitiateInterestRateSwapBootstrapHelper2(xDll) ;
			registerxlInitiateOvernightIndexedBootstrapHelper(xDll) ;
            registerxlInitiateInterpolatedCurve(xDll) ;

    } ;

inline void unregister_curve(const XLOPER & xDll) {
            
			/**/
			unregisterxlInitiateSwapCurveUnitedStates(xDll) ;
            unregisterxlInitiateSwapCurveAustralia(xDll) ;
			/**/
			
			unregisterxlInitiateShiftedCurve(xDll) ;
            unregisterxlInitiateFittedBondDiscountCurve(xDll) ;
            unregisterxlInitiateDepositBootstrapHelper(xDll) ;
			unregisterxlInitiateDepositBootstrapHelper2(xDll) ;
			unregisterxlInitiateDepositFutureBootstrapHelper(xDll) ;
            unregisterxlInitiateInterestRateSwapBootstrapHelper(xDll) ;
			unregisterxlInitiateInterestRateSwapBootstrapHelper2(xDll) ;
			unregisterxlInitiateOvernightIndexedBootstrapHelper(xDll) ;
            unregisterxlInitiateInterpolatedCurve(xDll) ;

    } ;

#endif