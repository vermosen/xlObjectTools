/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateInterpolatedCurve(const XLOPER & xDll) {

            // register the function xlInitiateIntepolatedCurve
    Excel(xlfRegister, 0, 14, & xDll,
        TempStrNoSize("\x1B""xlInitiateInterpolatedCurve"),
        TempStrNoSize("\x06""CCPPP#"),
		TempStrNoSize("\x18""OBJECT.CURVE.INTERPOLATE"),
		TempStrNoSize("\x32""object indentifier,calculation date,helper,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2B""This function creates an interpolated curve"),
		TempStrNoSize("\x11""Object identifier"),
		TempStrNoSize("\x14""The calculation date"),
		TempStrNoSize("\x14""The curve components"),
		TempStrNoSize("\x19""Trigger for recalculation"));

}

inline void unregisterxlInitiateInterpolatedCurve(const XLOPER & xDll) {

    XLOPER xlRegID ;

		// unregister the function xlInitiateIntepolatedCurve
	Excel(xlfRegister, 0, 14, &xDll,
		TempStrNoSize("\x1B""xlInitiateInterpolatedCurve"),
		TempStrNoSize("\x06""CCPPP#"),
		TempStrNoSize("\x18""OBJECT.CURVE.INTERPOLATE"),
		TempStrNoSize("\x32""object indentifier,calculation date,helper,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2B""This function creates an interpolated curve"),
		TempStrNoSize("\x11""Object identifier"),
		TempStrNoSize("\x14""The calculation date"),
		TempStrNoSize("\x14""The curve components"),
		TempStrNoSize("\x19""Trigger for recalculation"));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x1B""xlInitiateInterpolatedCurve")) ;

    Excel4(xlfUnregister, 0, 1, & xlRegID) ;

}
