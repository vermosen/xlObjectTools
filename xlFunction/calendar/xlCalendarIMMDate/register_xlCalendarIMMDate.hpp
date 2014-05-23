/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarIMMDate(const XLOPER & xDll) {

	// register the xlCalendarIMMDate function
	Excel(xlfRegister, 0, 12, &xDll,
		TempStrNoSize("\x11""xlCalendarIMMDate"),
		TempStrNoSize("\x04""BPC#"),
		TempStrNoSize("\x11""CALENDAR.IMM.DATE"),
		TempStrNoSize("\x13""start date,IMM code"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x45""This function returns the date corresponding to the IMM code provided"),
		TempStrNoSize("\x0E""The start date"),
		TempStrNoSize("\x0C""The IMM date"));

}

inline void unregisterxlCalendarIMMDate(const XLOPER & xDll) {

    XLOPER xlRegID ;

	// unregister the xlCalendarIMMDate function
	Excel(xlfRegister, 0, 12, &xDll,
		TempStrNoSize("\x11""xlCalendarIMMDate"),
		TempStrNoSize("\x04""BPC#"),
		TempStrNoSize("\x11""CALENDAR.IMM.DATE"),
		TempStrNoSize("\x13""start date,IMM code"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x45""This function returns the date corresponding to the IMM code provided"),
		TempStrNoSize("\x0E""The start date"),
		TempStrNoSize("\x0C""The IMM date"));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x11""xlCalendarIMMDate"));

    Excel4(xlfUnregister, 0, 1, & xlRegID);

}