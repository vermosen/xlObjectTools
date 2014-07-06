/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCurveZeroRate(const XLOPER & xDll) {

        // register the function xlCurveZeroRate
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0F""xlCurveZeroRate"),
            TempStrNoSize("\x06""PCECP#"),
            TempStrNoSize("\x0F""CURVE.ZERO.RATE"),
            TempStrNoSize("\x1F""curve,effective date,convention"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""This function gives yield curve's zero rate corresponding to the passed maturity date and convention"),
            TempStrNoSize("\x10""Curve Identifier"),
            TempStrNoSize("\x11""The maturity date"),
            TempStrNoSize("\x1F""The yield convention identifier"),
            TempStrNoSize("\x1B""Trigger for recalculation   ")) ;

    }

inline void unregisterxlCurveZeroRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // release the function xlCurveZeroRate
		Excel(xlfRegister, 0, 14, &xDll,
			TempStrNoSize("\x0F""xlCurveZeroRate"),
			TempStrNoSize("\x06""PCECP#"),
			TempStrNoSize("\x0F""CURVE.ZERO.RATE"),
			TempStrNoSize("\x1F""curve,effective date,convention"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x64""This function gives yield curve's zero rate corresponding to the passed maturity date and convention"),
			TempStrNoSize("\x10""Curve Identifier"),
			TempStrNoSize("\x11""The maturity date"),
			TempStrNoSize("\x1F""The yield convention identifier"),
			TempStrNoSize("\x1B""Trigger for recalculation   "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0F""xlCurveZeroRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }