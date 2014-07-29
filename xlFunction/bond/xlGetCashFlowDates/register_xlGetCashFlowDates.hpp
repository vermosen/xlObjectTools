/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlGetCashFlowDates(const XLOPER & xDll) {

        // register the function xlGetCashFlowDates
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlGetCashFlowDates"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x19""INSTRUMENT.CASHFLOW.DATES"),
            TempStrNoSize("\x1D""instrument identifier,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x33""This function displays the cashflow dates of a bond"),
            TempStrNoSize("\x19""The instrument identifier"),
            TempStrNoSize("\x25""Triggers the computation (optional)  ")) ;

    }

inline void unregisterxlGetCashFlowDates(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregister the function xlGetCashFlowDates
		Excel(xlfRegister, 0, 12, &xDll,
			TempStrNoSize("\x12""xlGetCashFlowDates"),
			TempStrNoSize("\x04""PCP#"),
			TempStrNoSize("\x19""INSTRUMENT.CASHFLOW.DATES"),
			TempStrNoSize("\x1D""instrument identifier,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x33""This function displays the cashflow dates of a bond"),
			TempStrNoSize("\x19""The instrument identifier"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlGetCashFlowDates")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }