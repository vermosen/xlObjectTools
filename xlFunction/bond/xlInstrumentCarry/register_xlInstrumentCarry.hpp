/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentCarry(const XLOPER & xDll) {

             // register the function xlInstrumentCarry
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x11""xlInstrumentCarry"),
            TempStrNoSize("\x08""PCEEECP#"),
            TempStrNoSize("\x0A""BOND.CARRY"),
            TempStrNoSize("\x4F""instrument identifier,start date,end date,initial yield,rate convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x59""This function calculates the carry of the instrument for a given yield and a carry period"),
            TempStrNoSize("\x19""The instrument identifier"),
            TempStrNoSize("\x14""The carry start date"),
            TempStrNoSize("\x12""The carry end date"),
            TempStrNoSize("\x14""The instrument yield"),
            TempStrNoSize("\x1E""The rate convention identifier"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

    }

inline void unregisterxlInstrumentCarry(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// release the function xlInstrumentCarry
		Excel(xlfRegister, 0, 16, &xDll,
			TempStrNoSize("\x11""xlInstrumentCarry"),
			TempStrNoSize("\x08""PCEEECP#"),
			TempStrNoSize("\x0A""BOND.CARRY"),
			TempStrNoSize("\x4F""instrument identifier,start date,end date,initial yield,rate convention,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x59""This function calculates the carry of the instrument for a given yield and a carry period"),
			TempStrNoSize("\x19""The instrument identifier"),
			TempStrNoSize("\x14""The carry start date"),
			TempStrNoSize("\x12""The carry end date"),
			TempStrNoSize("\x14""The instrument yield"),
			TempStrNoSize("\x1E""The rate convention identifier"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x11""xlInstrumentCarry"));

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }