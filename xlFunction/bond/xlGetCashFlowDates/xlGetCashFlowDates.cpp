/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlGetCashFlowDates/xlGetCashFlowDates.hpp>

// retrieve the cashflow dates of a bond
DLLEXPORT xloper * xlGetCashFlowDates (
	const char * objectID_,
    xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlGetCashFlowDates")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;
        ObjectHandler::validateRange(trigger_, "trigger") ;		// validate trigger range
        std::vector<double> returnVector ;						// date vector in excel format

        OH_GET_UNDERLYING(myBond, 
                            objectID_, 
                            QuantLibAddin::Bond, 
                            QuantLib::Bond)

        returnVector.push_back(myBond.issueDate().serialNumber()) ;

        for (unsigned int i = 0 ;								// retrieve cashflow dates
				i < myBond.cashflows().size() - 1 ; i++)
                
			returnVector.push_back(
				myBond.cashflows()[i]->date().serialNumber()) ;

        static OPER returnOper ;
        ObjectHandler::vectorToOper<double>(returnVector, returnOper) ;
        return & returnOper ;

    } catch (std::exception & e) {

		// error
		ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
		static XLOPER returnOper;
		returnOper.xltype = xltypeErr;
		returnOper.val.err = xlerrValue;
		return &returnOper;

    }

} ;

