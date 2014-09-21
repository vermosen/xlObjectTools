/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentAccruedAmount(const XLOPER & xDll) {

             // register the function xlInstrumentAccruedAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x19""xlInstrumentAccruedAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x13""BOND.ACCRUAL.AMOUNT"),
            TempStrNoSize("\x27""bond identifier,settlement date,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x57""This function gives the accrual amount of a given instrument on a given settlement date"),
            TempStrNoSize("\x13""The bond identifier"),
            TempStrNoSize("\x25""The settlement date of the instrument"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

    }

inline void unregisterxlInstrumentAccruedAmount(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// release the function xlInstrumentAccruedAmount
		Excel(xlfRegister, 0, 13, &xDll,
			TempStrNoSize("\x19""xlInstrumentAccruedAmount"),
			TempStrNoSize("\x05""PCPP#"),
			TempStrNoSize("\x13""BOND.ACCRUAL.AMOUNT"),
			TempStrNoSize("\x27""bond identifier,settlement date,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x57""This function gives the accrual amount of a given instrument on a given settlement date"),
			TempStrNoSize("\x13""The bond identifier"),
			TempStrNoSize("\x25""The settlement date of the instrument"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x19""xlInstrumentAccruedAmount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }