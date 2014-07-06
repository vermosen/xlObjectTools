/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlCurveZeroRate/xlCurveZeroRate.hpp>

// returns the zero rate corresponding to a given date for a given convention
DLLEXPORT xloper * xlCurveZeroRate (const char * curveId_,
                                    const double * effectiveDate_,
                                    const char * conventionId_,
                                    xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCurveZeroRate")) ;

        try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* création de la date */
            QuantLib::Date effectiveDate(static_cast<QuantLib::BigInteger>(* effectiveDate_)) ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

            // the convention
            OH_GET_REFERENCE(conventionPtr, 
                            conventionId_, 
                            QuantLibAddin::interestRateConventionObject, 
                            QuantLib::InterestRate)

            // the yield curve
			OH_GET_REFERENCE(CurvePtr,
							 curveId_,
							 QuantLibAddin::YieldTermStructure,
							 QuantLib::YieldTermStructure)
            
			// check on date coherence
			QL_ENSURE(effectiveDate > CurvePtr->referenceDate(),
                        "invalid date !") ;

			double returnValue = CurvePtr->zeroRate(
				effectiveDate,
				conventionPtr->dayCounter(),
				conventionPtr->compounding(),
				conventionPtr->frequency(),
				true);

			static OPER returnOper;
			ObjectHandler::scalarToOper(returnValue, returnOper);
			return &returnOper;

        } catch (std::exception & e) {

				ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
				static XLOPER returnOper;
				returnOper.xltype = xltypeErr;
				returnOper.val.err = xlerrValue;
				return &returnOper;

        }

}

