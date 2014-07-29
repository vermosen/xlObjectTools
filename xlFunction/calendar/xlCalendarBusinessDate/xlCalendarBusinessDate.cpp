/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarBusinessDate/xlCalendarBusinessDate.hpp>

// calculates the date corresponding to a 
// number of business days in a given calendar
DLLEXPORT xloper * xlCalendarBusinessDate(
	double * calculationDate_,
	char * calendarID_,
	long * spotDays_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCalendarBusinessDate")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

        double returnValue = ObjectHandler::calendarFactory()(calendarID_).advance(
			QuantLib::Date(static_cast<QuantLib::BigInteger>(* calculationDate_)),
            * spotDays_,
            QuantLib::Days).serialNumber() ;
		
		static XLOPER returnOper;
		ObjectHandler::scalarToOper(returnValue, returnOper);
		return &returnOper;

    } catch (std::exception & e) {

		// error
		ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
		static XLOPER returnOper;
		returnOper.xltype = xltypeErr;
		returnOper.val.err = xlerrValue;
		return &returnOper;

    }

}       