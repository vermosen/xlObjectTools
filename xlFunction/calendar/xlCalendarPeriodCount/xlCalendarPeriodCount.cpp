/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 20/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarPeriodCount/xlCalendarPeriodCount.hpp>

	// calculate gap end
DLLEXPORT double xlCalendarPeriodCount (xloper * calculationDate_, 
                                        const char * period_,
                                        xloper * calendar_,
                                        xloper * endDateConvention_,
                                        xloper * endOfMonth_) {

boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlCalendarPeriodCount")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ; 

        ObjectHandler::validateRange(calculationDate_  , "calculation Date"   );	// range validation
        ObjectHandler::validateRange(calendar_         , "calendar"           );
        ObjectHandler::validateRange(endDateConvention_, "end Date Convention");
        ObjectHandler::validateRange(endOfMonth_       , "end of Month"       );

        ObjectHandler::ConvertOper myOper1(* calculationDate_),						// xloper
                                    myOper2(* calendar_),
                                    myOper3(* endDateConvention_),
                                    myOper4(* endOfMonth_) ;

        QuantLib::Date calculationDate(												// calculation date
            myOper1.missing() ?
            QuantLib::Date() :
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

        QuantLib::Calendar calendar(												// calendar
            myOper2.missing() ?
            QuantLib::WeekendsOnly() :
            ObjectHandler::calendarFactory()(static_cast<std::string>(myOper2))) ;

        QuantLib::BusinessDayConvention endDateConvention(							// business day convention
            myOper3.missing() ?
            QuantLib::Unadjusted :
            ObjectHandler::businessDayConventionFactory()(static_cast<std::string>(myOper3))) ;

        bool endOfMonth(															// EOM rule
            myOper4.missing() ?
            false :
            static_cast<bool>(myOper4)) ;

        return calendar.advance(calculationDate,									// period has to be provided
                                ObjectHandler::periodFactory()(period_),
                                endDateConvention,
                                endOfMonth).serialNumber() ;

    } catch (std::exception & e) {

        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
        return 0.0 ;

    }

}

