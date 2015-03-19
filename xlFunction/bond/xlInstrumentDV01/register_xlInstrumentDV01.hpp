/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentDV01(const XLOPER & xDll) {

	// register the function xlInstrumentDV01
	Excel(xlfRegister, 0, 16, &xDll,
		TempStrNoSize("\x10""xlInstrumentDV01"),
		TempStrNoSize("\x08""PCPPECP#"),
		TempStrNoSize("\x09""BOND.DV01"),
		TempStrNoSize("\x42""identifier,valuation date,settlement date,price,convention,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x14""xlObjectTools - Bond"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2C""This function calculates the instrument DV01"),
		TempStrNoSize("\x19""The instrument identifier"),
		TempStrNoSize("\x14""The instrument price"),
		TempStrNoSize("\x1D""The valuation date (optional)"),
		TempStrNoSize("\x1E""The settlement date (optional)"),
		TempStrNoSize("\x1E""The rate convention (optional)"),
		TempStrNoSize("\x25""Triggers the computation (optional)  "));

}

inline void unregisterxlInstrumentDV01(const XLOPER & xDll) {

    XLOPER xlRegID;

	// unregister the function xlInstrumentDV01
	Excel(xlfRegister, 0, 16, &xDll,
		TempStrNoSize("\x10""xlInstrumentDV01"),
		TempStrNoSize("\x08""PCPPECP#"),
		TempStrNoSize("\x09""BOND.DV01"),
		TempStrNoSize("\x42""identifier,valuation date,settlement date,price,convention,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x14""xlObjectTools - Bond"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2C""This function calculates the instrument DV01"),
		TempStrNoSize("\x19""The instrument identifier"),
		TempStrNoSize("\x14""The instrument price"),
		TempStrNoSize("\x1D""The valuation date (optional)"),
		TempStrNoSize("\x1E""The settlement date (optional)"),
		TempStrNoSize("\x1E""The rate convention (optional)"),
		TempStrNoSize("\x25""Triggers the computation (optional)  "));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x10""xlInstrumentDV01"));

    Excel4(xlfUnregister, 0, 1, & xlRegID);

}