/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlCurveReferenceDate/xlCurveReferenceDate.hpp>

	// Provides the reference date of the curve
DLLEXPORT double xlCurveReferenceDate (const char * curveId_,
                                       xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
		new ObjectHandler::FunctionCall("xlCurveSettlementDate")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

			// validate range
        ObjectHandler::validateRange(trigger_, "trigger");

            // get the curve -> reference ?
        OH_GET_OBJECT(CurvePtr, curveId_, ObjectHandler::Object)

        QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
            QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, 
										QuantLib::YieldTermStructure>()(CurvePtr);
                    
        return YieldCurveLibObj->referenceDate().serialNumber();

    } catch (std::exception & e) {

        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        return 0.0 ;

    }

}