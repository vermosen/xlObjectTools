/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateTimeSeries(const XLOPER & xDll) {

	// register the function xlInitiateTimeSeries
	Excel(xlfRegister, 0, 14, &xDll,
		TempStrNoSize("\x14""xlInitiateTimeSeries"),
		TempStrNoSize("\x06""CCPPP#"),
		TempStrNoSize("\x12""OBJECT.TIME.SERIES"),
		TempStrNoSize("\x27""object indentifier,dates,values,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2A""This function creates a time series object"),
		TempStrNoSize("\x11""Object Identifier"),
		TempStrNoSize("\x09""The dates"),
		TempStrNoSize("\x16""The corresponding data"),
		TempStrNoSize("\x1C""Trigger for recalculation   "));

    }

inline void unregisterxlInitiateTimeSeries(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// freed the function xlInitiateTimeSeries
		Excel(xlfRegister, 0, 14, &xDll,
			TempStrNoSize("\x14""xlInitiateTimeSeries"),
			TempStrNoSize("\x06""CCPPP#"),
			TempStrNoSize("\x12""OBJECT.TIME.SERIES"),
			TempStrNoSize("\x27""object indentifier,dates,values,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x16""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x2A""This function creates a time series object"),
			TempStrNoSize("\x11""Object Identifier"),
			TempStrNoSize("\x09""The dates"),
			TempStrNoSize("\x16""The corresponding data"),
			TempStrNoSize("\x1C""Trigger for recalculation   "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x10""xlInitiateTimeSeries")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }