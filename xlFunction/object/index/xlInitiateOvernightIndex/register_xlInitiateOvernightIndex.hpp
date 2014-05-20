/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 29/05/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateOvernightIndex(const XLOPER & xDll) {

	// register the fonction xlInitiateOvernightIndex
	Excel(xlfRegister, 0, 16, &xDll,
		TempStrNoSize("\x1A""xlInitiateOvernightIndex"),
		TempStrNoSize("\x08""CCPPCCP#"),
		TempStrNoSize("\x16""OBJECT.OVERNIGHT.INDEX"),
		TempStrNoSize("\x48""object indentifier,fixings,settlement days,calendar,annual basis,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x28""This function creates an overnight index"),
		TempStrNoSize("\x11""Object identifier"),
		TempStrNoSize("\x12""Fixing time series"),
		TempStrNoSize("\x1B""Settlment dayx of the index"),
		TempStrNoSize("\x0F""Fixing calendar"),
		TempStrNoSize("\x19""Annual basis of the index"),
		TempStrNoSize("\x19""Trigger for recalculation"));

}

inline void unregisterxlInitiateOvernightIndex(const XLOPER & xDll) {

    XLOPER xlRegID ;

	// unregister the fonction xlInitiateOvernightIndex
	Excel(xlfRegister, 0, 16, &xDll,
		TempStrNoSize("\x1A""xlInitiateOvernightIndex"),
		TempStrNoSize("\x08""CCPPCCP#"),
		TempStrNoSize("\x16""OBJECT.OVERNIGHT.INDEX"),
		TempStrNoSize("\x48""object indentifier,fixings,settlement days,calendar,annual basis,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x28""This function creates an overnight index"),
		TempStrNoSize("\x11""Object identifier"),
		TempStrNoSize("\x12""Fixing time series"),
		TempStrNoSize("\x1B""Settlment dayx of the index"),
		TempStrNoSize("\x0F""Fixing calendar"),
		TempStrNoSize("\x19""Annual basis of the index"),
		TempStrNoSize("\x19""Trigger for recalculation"));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x1A""xlInitiateOvernightIndex"));

    Excel4(xlfUnregister, 0, 1, & xlRegID);

}
