/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlCalendarIMMDate.hpp"

// compute the date corresponding to the IMM code
DLLEXPORT double xlCalendarIMMDate (xloper * calculationDate_, 
                                    char * immCode_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCalendarIMMDate"));

        try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

            ObjectHandler::validateRange(calculationDate_, "calculation Date");

            ObjectHandler::ConvertOper myOper(* calculationDate_);

            QuantLib::Date calculationDate(									// calculation date
                myOper.missing() ?
                QuantLib::Date() :
                QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper)));

            return QuantLib::Date(											// next IMM date
                QuantLib::IMM::date(
					std::string(immCode_), 
					calculationDate)).serialNumber();

        } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
            return 0;

        }

}