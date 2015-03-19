/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentPrice(const XLOPER & xDll) {

    // register the function registerxlInstrumentPrice
	Excel(	xlfRegister, 0, 15, &xDll,
			TempStrNoSize("\x11""xlInstrumentPrice"),
			TempStrNoSize("\x07""PCPEPP#"),
			TempStrNoSize("\x0A""BOND.PRICE"),
			TempStrNoSize("\x33""identifier,settlement date,yield,convention,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x4D""This function computes the bond price from its yield for the given convention"),
			TempStrNoSize("\x15""Instrument identifier"),
			TempStrNoSize("\x25""instrument settlement date (optional)"),
			TempStrNoSize("\x10""instrument yield"),
			TempStrNoSize("\x24""rate convention identifer (optional)"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

}

inline void unregisterxlInstrumentPrice(const XLOPER & xDll) {

    XLOPER xlRegID ;

    // release the function registerxlInstrumentPrice
	Excel(	xlfRegister, 0, 15, &xDll,
			TempStrNoSize("\x11""xlInstrumentPrice"),
			TempStrNoSize("\x07""PCPEPP#"),
			TempStrNoSize("\x0A""BOND.PRICE"),
			TempStrNoSize("\x33""identifier,settlement date,yield,convention,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x4D""This function computes the bond price from its yield for the given convention"),
			TempStrNoSize("\x15""Instrument identifier"),
			TempStrNoSize("\x25""instrument settlement date (optional)"),
			TempStrNoSize("\x10""instrument yield"),
			TempStrNoSize("\x24""rate convention identifer (optional)"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x11""xlInstrumentPrice")) ;

    Excel4(xlfUnregister, 0, 1, & xlRegID) ;

}