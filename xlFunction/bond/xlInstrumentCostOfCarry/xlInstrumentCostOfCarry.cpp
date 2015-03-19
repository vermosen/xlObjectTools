/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/08/10
 *  Copyright 2009. All /rights r/eserved.
 *
 */

#include "xlInstrumentCostOfCarry.hpp"

// compute instrument's cost-of-carry
DLLEXPORT xloper * xlInstrumentCostOfCarry (const char *	objectID_       ,
                                            const char *	curveId_		,
                                            const double *	instrumentPrice_,
                                            const double *	carryStartDate_ ,
                                            const double *	carryEndDate_   ,
                                            xloper *		trigger_		) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentCostOfCarry"));

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");		// error on wizard call

        ObjectHandler::validateRange(trigger_, "trigger");			// validate the triggers

        OH_GET_REFERENCE(	instrumentPtr       ,					// get the bond
							objectID_			,
                            QuantLibAddin::Bond	,
                            QuantLib::Bond		)

        OH_GET_OBJECT(	curvePtr				,					// get the yield curve
						curveId_				, 
						ObjectHandler::Object	)	

		// create the dates
        QuantLib::Date carryStartDate(static_cast<QuantLib::BigInteger> (* carryStartDate_)),
                       carryEndDate  (static_cast<QuantLib::BigInteger> (* carryEndDate_  )) ;


        QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
            QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;

        QL_REQUIRE(carryStartDate <= carryEndDate,					// control on the dates
			"end date is situated before start date");
        QL_REQUIRE(YieldCurveLibObj->referenceDate() <= carryStartDate, 
			"wrong curve reference date");

        double returnValue = 0.0;									// the amount to return

        QL_REQUIRE(instrumentPtr->maturityDate() >= carryEndDate,	// check on the instrument dates
			"instrument matures before end date !");
        QL_REQUIRE(instrumentPtr->issueDate() <= carryStartDate, 
			"instrument issues after begin date !");

		// add the capitalized start amount and substract
		// the final accrual amount
        returnValue += *instrumentPrice_ + instrumentPtr->accruedAmount(carryStartDate);
        returnValue *= (YieldCurveLibObj->discount(carryStartDate, true) 
            / YieldCurveLibObj->discount(carryEndDate, true) - 1);

        // iterate on the cash-flows
        for (std::vector<boost::shared_ptr<QuantLib::CashFlow> >::const_iterator
                It = instrumentPtr->cashflows().begin() ;
                It != instrumentPtr->cashflows().end() ; ++It) {

				// check on the dates
                if(It->get()->date() >= carryStartDate && It->get()->date() <= carryEndDate)

                        // CF_i * discount_j / discount_i
                        returnValue += It->get()->amount() * (YieldCurveLibObj->discount(It->get()->date(), true)
                                        / YieldCurveLibObj->discount(carryEndDate, true) - 1) ;

                    }

        static OPER returnOper;
        ObjectHandler::scalarToOper(returnValue, returnOper);
		return &returnOper;

    } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
            static XLOPER returnOper;
            ObjectHandler::scalarToOper(e.what(), returnOper);
            return & returnOper;

        }
};

