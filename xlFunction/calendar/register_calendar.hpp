/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_calendar_hpp
#define register_calendar_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/calendar/xlCalendarBusinessDate/register_xlCalendarBusinessDate.hpp>

#include <xlFunction/calendar/xlCalendarDaycount/register_xlCalendarDaycount.hpp>

#include <xlFunction/calendar/xlCalendarPeriodCount/register_xlCalendarPeriodCount.hpp>

#include <xlFunction/calendar/xlCalendarIMMDate/register_xlCalendarIMMDate.hpp>

#include <xlFunction/calendar/xlCalendarNextIMMCode/register_xlCalendarNextIMMCode.hpp>

inline void register_calendar(const XLOPER & xDll) {
    

                    // register calendar
            registerxlCalendarBusinessDate(xDll) ;

            registerxlCalendarDaycount(xDll) ;

            registerxlCalendarPeriodCount(xDll) ;

            registerxlCalendarIMMDate(xDll) ;

            registerxlCalendarNextIMMCode(xDll) ;
   
    
    } ;

inline void unregister_calendar(const XLOPER & xDll) {
    

                    // register calendar
            unregisterxlCalendarBusinessDate(xDll) ;

            unregisterxlCalendarDaycount(xDll) ;

            unregisterxlCalendarPeriodCount(xDll) ;

            unregisterxlCalendarIMMDate(xDll) ;

            unregisterxlCalendarNextIMMCode(xDll) ;
   
    
    } ;


#endif
