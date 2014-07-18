/*
*  xlObjectTools
*
*  Created by Jean-Matthieu VERMOSEN on 31/05/09
*  Copyright 2009. All rights reserved.
*
*/

#include <xlFunction/addin/xlRetrieveError/xlRetrieveError.hpp>

// retrieve the current error associated to a range
DLLEXPORT xloper * xlRetrieveError(xloper * range_,
								   xloper * trigger_) {

	boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
		new ObjectHandler::FunctionCall("xlRetrieveError"));

	try {

		QL_ENSURE(!functionCall->calledByFunctionWizard(), "");

		ObjectHandler::validateRange(trigger_, "trigger");
		
		// special case, do not valide range
		// (since it is supposed to be an error)
		//ObjectHandler::validateRange(range_, "range");

		static XLOPER returnOper;

		ObjectHandler::scalarToOper(
			ObjectHandler::RepositoryXL::instance().retrieveError(range_),
			returnOper);

		return &returnOper;

	} catch (std::exception & e) {

		ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
		static XLOPER returnOper;
		ObjectHandler::scalarToOper(e.what(), returnOper);
		return &returnOper;

	}

}