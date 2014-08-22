/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateFittedBondDiscountCurve(const XLOPER & xDll) {

        // Register the function xlInitiateFittedBondDiscountCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve"),
            TempStrNoSize("\x0B""CCPPPPCCPP#"),
            TempStrNoSize("\x17""INSTANCE.AJUSTED.CURVE"),
            TempStrNoSize("\x84""object identifier,calculation date,settlement date,instrument identifiers,quotes,calendar,fitting method,bond selection rule,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3F""This function creates a curve fitted on the selected intruments"),
            TempStrNoSize("\x15""The object identifier"),
            TempStrNoSize("\x14""The calculation date"),
            TempStrNoSize("\x20""The settlement date of the curve"),
            TempStrNoSize("\x25""The instruments used to fit the curve"),
            TempStrNoSize("\x1D""The quotes of the instruments"),
            TempStrNoSize("\x19""The calendar of the curve"),
            TempStrNoSize("\x18""The curve fitting method"),
			TempStrNoSize("\x1D""The instrument selection rule"),
            TempStrNoSize("\x1B""Trigger for recalculation  "));

    }


inline void unregisterxlInitiateFittedBondDiscountCurve(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// Unregister the function xlInitiateFittedBondDiscountCurve
		Excel(xlfRegister, 0, 19, &xDll,
			TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve"),
			TempStrNoSize("\x0B""CCPPPPCCPP#"),
			TempStrNoSize("\x17""INSTANCE.AJUSTED.CURVE"),
			TempStrNoSize("\x84""object identifier,calculation date,settlement date,instrument identifiers,quotes,calendar,fitting method,bond selection rule,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x17""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x3F""This function creates a curve fitted on the selected intruments"),
			TempStrNoSize("\x15""The object identifier"),
			TempStrNoSize("\x14""The calculation date"),
			TempStrNoSize("\x20""The settlement date of the curve"),
			TempStrNoSize("\x25""The instruments used to fit the curve"),
			TempStrNoSize("\x1D""The quotes of the instruments"),
			TempStrNoSize("\x19""The calendar of the curve"),
			TempStrNoSize("\x18""The curve fitting method"),
			TempStrNoSize("\x1D""The instrument selection rule"),
			TempStrNoSize("\x1B""Trigger for recalculation  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }