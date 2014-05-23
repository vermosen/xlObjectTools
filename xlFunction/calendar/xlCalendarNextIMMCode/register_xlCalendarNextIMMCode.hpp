/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarNextIMMCode(const XLOPER & xDll) {

            // Register the function xlNextImmCode
	Excel(xlfRegister, 0, 11, &xDll,
		TempStrNoSize("\x15""xlCalendarNextIMMCode"),
		TempStrNoSize("\x03""CP#"),
		TempStrNoSize("\x16""CALENDAR.NEXT.IMM.CODE"),
		TempStrNoSize("\x0A""start date"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x3D""This function computes the IMM code next to the date provided"),
		TempStrNoSize("\x0E""The start date"));

}

inline void unregisterxlCalendarNextIMMCode(const XLOPER & xDll) {

    XLOPER xlRegID ;

	// Unregister the function xlNextImmCode
	Excel(xlfRegister, 0, 11, &xDll,
		TempStrNoSize("\x15""xlCalendarNextIMMCode"),
		TempStrNoSize("\x03""CP#"),
		TempStrNoSize("\x16""CALENDAR.NEXT.IMM.CODE"),
		TempStrNoSize("\x0A""start date"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x3D""This function computes the IMM code next to the date provided"),
		TempStrNoSize("\x0E""The start date"));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x15""xlCalendarNextIMMCode")) ;

    Excel4(xlfUnregister, 0, 1, & xlRegID) ;

}