/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 20/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarPeriodCount(const XLOPER & xDll) {

    // register the function xlCalendarPeriodCount
	Excel(xlfRegister, 0, 15, &xDll,
		TempStrNoSize("\x15""xlCalendarPeriodCount"),
		TempStrNoSize("\x07""BPCPPP#"),
		TempStrNoSize("\x0C""CALENDAR.GAP"),
		TempStrNoSize("\x2E""start date,period,calendar,convention,EOM rule"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x40""This function returns the date corresponding to the gap provided"),
		TempStrNoSize("\x0E""The start date"),
		TempStrNoSize("\x20""Period identifier (O/N, 1W, etc)"),
		TempStrNoSize("\x12""Reference Calendar"),
		TempStrNoSize("\x24""End of period adjustement convention"),
		TempStrNoSize("\x14""End-of-month rule   "));

}

inline void unregisterxlCalendarPeriodCount(const XLOPER & xDll) {

    XLOPER xlRegID ;

	// unregister the function xlCalendarPeriodCount
	Excel(xlfRegister, 0, 15, &xDll,
		TempStrNoSize("\x15""xlCalendarPeriodCount"),
		TempStrNoSize("\x07""BPCPPP#"),
		TempStrNoSize("\x0C""CALENDAR.GAP"),
		TempStrNoSize("\x2E""start date,period,calendar,convention,EOM rule"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x18""xlObjectTools - Calendar"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x40""This function returns the date corresponding to the gap provided"),
		TempStrNoSize("\x0E""The start date"),
		TempStrNoSize("\x20""Period identifier (O/N, 1W, etc)"),
		TempStrNoSize("\x12""Reference Calendar"),
		TempStrNoSize("\x24""End of period adjustement convention"),
		TempStrNoSize("\x14""End-of-month rule   "));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x15""xlCalendarPeriodCount")) ;

    Excel4(xlfUnregister, 0, 1, & xlRegID) ;

}
