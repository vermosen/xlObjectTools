/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarBusinessDate(const XLOPER & xDll) {

        // registers the function xlBusinessDate
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x16""xlCalendarBusinessDate"),
            TempStrNoSize("\x05""PECN#"),
            TempStrNoSize("\x16""CALENDAR.BUSINESS.DAYS"),
            TempStrNoSize("\x24""starting date,calendar,business days"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x60""This function calculates the date corresponding to a number of business days in a given calendar"),
            TempStrNoSize("\x11""The starting date"),
            TempStrNoSize("\x0C""The calendar"),
            TempStrNoSize("\x24""The number of business days to add  ")) ;

    }

inline void unregisterxlCalendarBusinessDate(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregisters the function xlBusinessDate
		Excel(xlfRegister, 0, 13, &xDll,
			TempStrNoSize("\x16""xlCalendarBusinessDate"),
			TempStrNoSize("\x05""PECN#"),
			TempStrNoSize("\x16""CALENDAR.BUSINESS.DAYS"),
			TempStrNoSize("\x24""starting date,calendar,business days"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x19""xlObjectTools - Calendar"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x60""This function calculates the date corresponding to a number of business days in a given calendar"),
			TempStrNoSize("\x11""The starting date"),
			TempStrNoSize("\x0C""The calendar"),
			TempStrNoSize("\x24""The number of business days to add  "));


        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x16""xlCalendarBusinessDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }