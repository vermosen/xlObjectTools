/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentCostOfCarry(const XLOPER & xDll) {

    // register the function xlInstrumentCostOfCarry
	Excel(xlfRegister, 0, 16, &xDll,
		TempStrNoSize("\x17""xlInstrumentCostOfCarry"),
		TempStrNoSize("\x08""PCCEEEP#"),
		TempStrNoSize("\x18""INSTRUMENT.COST.OF.CARRY"),
		TempStrNoSize("\x32""instrument,curve,price,start date,end date,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x14""xlObjectTools - Bond"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x92""This function calculates the final price of the bond deducing cost-of-carry. The intermediates coupons are reinvested at the specified curve rates"),
		TempStrNoSize("\x15""Instrument identifier"),
		TempStrNoSize("\x10""Curve identifier"),
		TempStrNoSize("\x36""Price of the instrument at the beginning of the period"),
		TempStrNoSize("\x1E""Start date of the carry period"),
		TempStrNoSize("\x1C""End date of the carry period"),
		TempStrNoSize("\x25""Triggers the computation (optional)  "));

    }


inline void unregisterxlInstrumentCostOfCarry(const XLOPER & xDll) {

        XLOPER xlRegID;

		// unregister the function xlInstrumentCostOfCarry
		Excel(xlfRegister, 0, 16, &xDll,
			TempStrNoSize("\x17""xlInstrumentCostOfCarry"),
			TempStrNoSize("\x08""PCCEEEP#"),
			TempStrNoSize("\x18""INSTRUMENT.COST.OF.CARRY"),
			TempStrNoSize("\x32""instrument,curve,price,start date,end date,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x14""xlObjectTools - Bond"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x92""This function calculates the final price of the bond deducing cost-of-carry. The intermediates coupons are reinvested at the specified curve rates"),
			TempStrNoSize("\x15""Instrument identifier"),
			TempStrNoSize("\x10""Curve identifier"),
			TempStrNoSize("\x36""Price of the instrument at the beginning of the period"),
			TempStrNoSize("\x1E""Start date of the carry period"),
			TempStrNoSize("\x1C""End date of the carry period"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x17""xlInstrumentCostOfCarry")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }