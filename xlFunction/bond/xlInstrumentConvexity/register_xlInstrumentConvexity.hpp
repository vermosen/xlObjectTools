/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentConvexity(const XLOPER & xDll) {

		// registers the function xlInstrumentConvexity
		Excel(xlfRegister, 0, 16, &xDll,
			TempStrNoSize("\x15""xlInstrumentConvexity"),
			TempStrNoSize("\x08""PCPPECP#"),
			TempStrNoSize("\x0E""BOND.CONVEXITY"),
			TempStrNoSize("\x38""identifier,value date,settlement,price,convetion,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x14""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x5C""This function calculates the convexity of a given bond for a given price and settlement date"),
			TempStrNoSize("\x1A""The name of the instrument"),
			TempStrNoSize("\x1B""The price of the instrument"),
			TempStrNoSize("\x1D""The valuation date (optional)"),
			TempStrNoSize("\x30""The settlement date of the instrument (optional)"),
			TempStrNoSize("\x30""The rate convention of the instrument (optional)"),
			TempStrNoSize("\x1C""Trigger for recalculation   "));


    }

inline void unregisterxlInstrumentConvexity(const XLOPER & xDll) {

        XLOPER xlRegID ;

		Excel(xlfRegister, 0, 16, &xDll,
			TempStrNoSize("\x15""xlInstrumentConvexity"),
			TempStrNoSize("\x08""PCPPECP#"),
			TempStrNoSize("\x0E""BOND.CONVEXITY"),
			TempStrNoSize("\x38""identifier,value date,settlement,price,convetion,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x14""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x5C""This function calculates the convexity of a given bond for a given price and settlement date"),
			TempStrNoSize("\x1A""The name of the instrument"),
			TempStrNoSize("\x1B""The price of the instrument"),
			TempStrNoSize("\x1D""The valuation date (optional)"),
			TempStrNoSize("\x30""The settlement date of the instrument (optional)"),
			TempStrNoSize("\x30""The rate convention of the instrument (optional)"),
			TempStrNoSize("\x19""Trigger for recalculation"));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x15""xlInstrumentConvexity"));

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }