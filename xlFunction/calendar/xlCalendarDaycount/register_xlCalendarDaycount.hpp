/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarDaycount(const XLOPER & xDll) {

        // registers the function xlCalendarDaycount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x12""xlCalendarDaycount"),
            TempStrNoSize("\x05""PEEC#"),
            TempStrNoSize("\x16""CALENDAR.YEAR.FRACTION"),
            TempStrNoSize("\x22""Start date,End date,daycount basis"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x58""This function calculates the year fraction corresponding to a start date and an end date"),
            TempStrNoSize("\x0E""The start date"),
            TempStrNoSize("\x0C""The end date"),
            TempStrNoSize("\x12""The annual basis  "));

    }

inline void unregisterxlCalendarDaycount(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregisters the function xlCalendarDaycount
		Excel(xlfRegister, 0, 13, &xDll,
			TempStrNoSize("\x12""xlCalendarDaycount"),
			TempStrNoSize("\x05""PEEC#"),
			TempStrNoSize("\x16""CALENDAR.YEAR.FRACTION"),
			TempStrNoSize("\x22""Start date,End date,daycount basis"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x19""xlObjectTools - Calendar"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x58""This function calculates the year fraction corresponding to a start date and an end date"),
			TempStrNoSize("\x0E""The start date"),
			TempStrNoSize("\x0C""The end date"),
			TempStrNoSize("\x12""The annual basis  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlCalendarDaycount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }