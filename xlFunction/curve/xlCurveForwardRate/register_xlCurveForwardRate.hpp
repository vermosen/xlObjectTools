/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCurveForwardRate(const XLOPER & xDll) {

		// Register the function xlCurveForwardRate
	Excel(xlfRegister, 0, 15, &xDll,
		TempStrNoSize("\x12""xlCurveForwardRate"),
		TempStrNoSize("\x07""BCEECP#"),
		TempStrNoSize("\x12""CURVE.FORWARD.RATE"),
		TempStrNoSize("\x31""curve identifier,time 1,time 2,convention,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x1B""xlObjectTools - Yield Curve"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x43""This function computes the forward rate for the corresponding dates"),
		TempStrNoSize("\x10""Curve identifier"),
		TempStrNoSize("\x10""The forward date"),
		TempStrNoSize("\x11""The maturity date"),
		TempStrNoSize("\x20""The identifier of the convention"),
		TempStrNoSize("\x1B""Trigger for recalculation  "));

}

inline void unregisterxlCurveForwardRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// Unregister the function xlCurveForwardRate
		Excel(xlfRegister, 0, 15, &xDll,
			TempStrNoSize("\x12""xlCurveForwardRate"),
			TempStrNoSize("\x07""BCEECP#"),
			TempStrNoSize("\x12""CURVE.FORWARD.RATE"),
			TempStrNoSize("\x31""curve identifier,time 1,time 2,convention,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x1B""xlObjectTools - Yield Curve"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x43""This function computes the forward rate for the corresponding dates"),
			TempStrNoSize("\x10""Curve identifier"),
			TempStrNoSize("\x10""The forward date"),
			TempStrNoSize("\x11""The maturity date"),
			TempStrNoSize("\x20""The identifier of the convention"),
			TempStrNoSize("\x1B""Trigger for recalculation  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlCurveForwardRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }