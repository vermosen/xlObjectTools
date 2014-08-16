/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarDaycount/xlCalendarDaycount.hpp>

// calculates the corresponding daycount basis
DLLEXPORT xloper * xlCalendarDaycount (double * calculationDate_, 
                                       double * endDate_,
                                       char * daycountBasis_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCalendarDaycount"));

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");
				
		double returnValue = ObjectHandler::daycountFactory()(daycountBasis_).yearFraction(
			QuantLib::Date(static_cast<QuantLib::BigInteger>(*calculationDate_)),
			QuantLib::Date(static_cast<QuantLib::BigInteger>(*endDate_)));

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