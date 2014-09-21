/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/math/xlSchurEigenVector/xlSchurEigenVector.hpp>

// compute and returns Schur decomposition's eigen vector of a matrix
DLLEXPORT xloper * xlSchurEigenVector(const char * objectID_,
                                      const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlSchurEigenVector")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

        ObjectHandler::validateRange(trigger_, "trigger");					// validate range

		OH_GET_REFERENCE(matrixObjectPtr,									// get the matrix object
			objectID_,
			QuantLibAddin::matrixObject,
			QuantLib::Matrix)

		QuantLib::SymmetricSchurDecomposition schur(*matrixObjectPtr);		// launch the decomposition

        static OPER returnOper;												// return value
		QuantLib::Matrix s = schur.eigenvectors();
        ObjectHandler::MatrixToOper(s, returnOper);
        return & returnOper;

    } catch (std::exception & e) {

        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        static OPER returnOper;
		returnOper.xltype = xltypeErr;
		returnOper.val.err = xlerrNA;
		return & returnOper;

    }
};
