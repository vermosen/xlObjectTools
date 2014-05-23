/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarNextIMMCode/xlCalendarNextIMMCode.hpp>

	// Computes the next IMM code
DLLEXPORT char * xlCalendarNextIMMCode (xloper * calculationDate_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCalendarNextIMMCode"));

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

        ObjectHandler::validateRange(calculationDate_, "calculation Date");

        ObjectHandler::ConvertOper myOper(* calculationDate_);

        QuantLib::Date calculationDate(
            myOper.missing() ?
            QuantLib::Date() :
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper)));

        static char ret[XL_MAX_STR_LEN];
        ObjectHandler::stringToChar(QuantLib::IMM::nextCode(calculationDate).c_str(), ret);
        return ret;

    } catch (std::exception & e) {

        static char ret[XL_MAX_STR_LEN];
        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        ObjectHandler::stringToChar(e.what(), ret);
        return ret;

    }

}