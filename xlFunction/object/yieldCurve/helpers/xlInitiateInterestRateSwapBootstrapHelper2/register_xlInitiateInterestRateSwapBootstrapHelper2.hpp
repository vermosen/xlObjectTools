/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateInterestRateSwapBootstrapHelper2(const XLOPER & xDll) {

             // registers the function xlInitiateInterestRateSwapBootstrapHelper2
	Excel(xlfRegister, 0, 22, &xDll,
		TempStrNoSize("\x2A""xlInitiateInterestRateSwapBootstrapHelper2"),
		TempStrNoSize("\x0E""PCCCPPPEPPCPP#"),
		TempStrNoSize("\x18""OBJECT.CURVE.HELPER.SWAP"),
		TempStrNoSize("\xBB""Object Id,tenor,calendar,settlement days,fixed leg frequency,fixed leg daycount basis,fixed leg rate,float leg frequency,float leg daycount basis,reference index,discounting curve,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x4C""This function creates an interest rate swap helper for interpolation purpose"),
		TempStrNoSize("\x15""The helper identifier"),
		TempStrNoSize("\x1E""The maturity tenor of the swap"),
		TempStrNoSize("\x13""Settlement calendar"),
		TempStrNoSize("\x0F""Settlement days"),
		TempStrNoSize("\x23""The frequency of the fixed rate leg"),
		TempStrNoSize("\x2D""The daycount convention of the fixed rate leg"),
		TempStrNoSize("\x1A""The fixed rate of the swap"),
		TempStrNoSize("\x21""The frequency of the floating leg"),
		TempStrNoSize("\x2A""The daycount convention of the floting leg"),
		TempStrNoSize("\x1A""The fixed rate of the swap"),
		TempStrNoSize("\x27""The reference index of the floating leg"),
		TempStrNoSize("\x20""The discounting curve (optional)"),
		TempStrNoSize("\x19""Trigger for recalculation"));

    }


inline void unregisterxlInitiateInterestRateSwapBootstrapHelper2(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregisters the function xlInitiateInterestRateSwapBootstrapHelper2
		Excel(xlfRegister, 0, 22, &xDll,
			TempStrNoSize("\x2A""xlInitiateInterestRateSwapBootstrapHelper2"),
			TempStrNoSize("\x0E""PCCCPPPEPPCPP#"),
			TempStrNoSize("\x18""OBJECT.CURVE.HELPER.SWAP"),
			TempStrNoSize("\xBB""Object Id,tenor,calendar,settlement days,fixed leg frequency,fixed leg daycount basis,fixed leg rate,float leg frequency,float leg daycount basis,reference index,discounting curve,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x16""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x4C""This function creates an interest rate swap helper for interpolation purpose"),
			TempStrNoSize("\x15""The helper identifier"),
			TempStrNoSize("\x1E""The maturity tenor of the swap"),
			TempStrNoSize("\x13""Settlement calendar"),
			TempStrNoSize("\x0F""Settlement days"),
			TempStrNoSize("\x23""The frequency of the fixed rate leg"),
			TempStrNoSize("\x2D""The daycount convention of the fixed rate leg"),
			TempStrNoSize("\x1A""The fixed rate of the swap"),
			TempStrNoSize("\x21""The frequency of the floating leg"),
			TempStrNoSize("\x2A""The daycount convention of the floting leg"),
			TempStrNoSize("\x1A""The fixed rate of the swap"),
			TempStrNoSize("\x27""The reference index of the floating leg"),
			TempStrNoSize("\x20""The discounting curve (optional)"),
			TempStrNoSize("\x19""Trigger for recalculation"));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x2A""xlInitiateInterestRateSwapBootstrapHelper2")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }