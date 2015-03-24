/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlZSpreadFromPrice/xlZSpreadFromPrice.hpp>

DLLEXPORT xloper * xlZSpreadFromPrice (const char	* instrumentId_		,
                                       const char	* curveId_			,
                                       const double * price_			,
                                       xloper		* conventionId_		,
                                       xloper		* settlementDate_	,
                                       xloper		* trigger_			) {
    
	boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
	new ObjectHandler::FunctionCall("xlZSpreadFromPrice")) ;

	try {

    QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

	// validate range
    ObjectHandler::validateRange(trigger_		, "trigger"			);
    ObjectHandler::validateRange(settlementDate_, "settlement Date"	);
    ObjectHandler::validateRange(conventionId_	, "convention Id"	);

	// the xlopers
    ObjectHandler::ConvertOper myOper1(* settlementDate_);
    ObjectHandler::ConvertOper myOper2(* conventionId_	);

	// the yield curve
	OH_GET_REFERENCE(	curvePtr							,
						curveId_							,
						QuantLibAddin::YieldTermStructure	,
						QuantLib::YieldTermStructure		)

	// the return value
    double returnValue = 0.0;

    // the bond
    OH_GET_REFERENCE(	instrumentPtr		, 
                        instrumentId_		, 
                        QuantLibAddin::Bond	,
                        QuantLib::Bond		)

	// settlement bond
    QuantLib::Date settlementDate(
		myOper1.missing() ?
		instrumentPtr->settlementDate(curvePtr->referenceDate()) :
        static_cast<QuantLib::Date>(myOper1));

	// defaults to act/365 annual yield convention
    if (myOper2.missing()) {
                    
            returnValue = QuantLib::BondFunctions::zSpread(
				* instrumentPtr				,
			    * price_					,
				curvePtr					,
                QuantLib::Actual365Fixed()	,
				QuantLib::Continuous		,
                QuantLib::Annual			,
                QuantLib::Unadjusted		,
				settlementDate				,
				1e-8, 100, 1.0				); 
                    
        }

    else {
                    
		// get the market convention
		OH_GET_REFERENCE(	conventionPtr								, 
                            static_cast<std::string>(myOper2)			, 
							QuantLibAddin::interestRateConventionObject	,
							QuantLib::InterestRate						)

		// compute the z-spread
        returnValue = QuantLib::BondFunctions::zSpread(
			* instrumentPtr							,
			* price_								,
			curvePtr								,
			conventionPtr->dayCounter()				,
			conventionPtr->compounding()				,
			conventionPtr->frequency()				,
            conventionPtr->businessDayConvention()	,
			settlementDate							,
			1e-8, 100, 1.0							);
                    
        }

	// return the result
	static XLOPER returnOper;
	ObjectHandler::scalarToOper(returnValue * 10000.0, returnOper);
	return & returnOper;
	
	} catch (std::exception & e) {

		ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
		static XLOPER returnOper;
		returnOper.xltype = xltypeErr;
		returnOper.val.err = xlerrValue;
		return & returnOper;

	}
}