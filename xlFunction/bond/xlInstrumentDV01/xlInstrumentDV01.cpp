/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentDV01/xlInstrumentDV01.hpp>

// compute the bond DV01
// TODO: make the convention to default on the bond convention
DLLEXPORT xloper * xlInstrumentDV01 (const char		* instrumentId_			,
                                     xloper			* npvDate_				,
                                     xloper			* settlementDate_		,
                                     const double	* instrumentCleanPrice_	,
                                     const char		* conventionId_			,
                                     xloper			* trigger_				) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentDV01"));

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

		// validate ranges
        ObjectHandler::validateRange(trigger_		, "trigger"			);
        ObjectHandler::validateRange(npvDate_		, "npv Date"		);
        ObjectHandler::validateRange(settlementDate_, "settlement Date"	);

		// the rate convention
		OH_GET_REFERENCE(	conventionPtr								,
							conventionId_								,
							QuantLibAddin::interestRateConventionObject	,
							QuantLib::InterestRate						)

		// we get the instrument
        OH_GET_UNDERLYING(	myBond				, 
                            instrumentId_		, 
                            QuantLibAddin::Bond	,
                            QuantLib::Bond		) 

		// the XLOPERS
        ObjectHandler::ConvertOper	myOper1(* npvDate_		 ), 
                                    myOper2(* settlementDate_);

        QuantLib::Date npvDate(
            myOper1.missing() ? 
            QuantLib::Date() : 
            static_cast<QuantLib::Date>(myOper1));

        QuantLib::Date settlementDate(
            myOper2.missing() ? 
            myBond.settlementDate(npvDate) : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper2)));

        QuantLib::Rate yield = 
			QuantLib::BondFunctions::yield(
				myBond									,
                * instrumentCleanPrice_					,
                conventionPtr->dayCounter()				,
                conventionPtr->compounding()				,
                conventionPtr->frequency()				,
                conventionPtr->businessDayConvention()	,
                settlementDate							,
                1e-8, 100								);

        QuantLib::Real returnValue = 
			QuantLib::BondFunctions::basisPointValue(
				myBond									,
                yield									,
                conventionPtr->dayCounter()				,
                conventionPtr->compounding()				,
                conventionPtr->frequency()				,
                conventionPtr->businessDayConvention()	,
                settlementDate							);

		static XLOPER returnOper;
        ObjectHandler::scalarToOper(returnValue, returnOper);
        return & returnOper;

    } catch (std::exception & e) {

        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

        #ifdef _DEBUG

            OutputDebugString(e.what()) ;

        #endif

        static XLOPER returnOper;
        returnOper.xltype = xltypeErr;
		returnOper.val.err = xlerrValue;
        return & returnOper;

    }
};