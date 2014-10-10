/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/volatilitySurface/helpers/xlInitiateSwaptionHelper/xlInitiateSwaptionHelper.hpp>

	// register a helper for a swaption
DLLEXPORT xloper * xlInitiateSwaptionHelper(const char * objectId_,
											const double * maturity_,
											const double * length_,
											const double * volatility_,
											const char * index_,
											const xloper * fixedLegTenor_,
											const xloper * fixedLegDaycounter_,
											const xloper * floatLegDaycounter_,
											const char * termStructure_,
											const xloper * errorType_,
											const xloper * strike_,
											const xloper * nominal_,
											const xloper * trigger_) {
    
   boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateSwaptionHelper"));

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

		// validate range
		ObjectHandler::validateRange(fixedLegTenor_     , "fixedLegTenor"	  );  
		ObjectHandler::validateRange(fixedLegDaycounter_, "fixedLegDaycounter");
		ObjectHandler::validateRange(floatLegDaycounter_, "floatLegDaycounter");
		ObjectHandler::validateRange(errorType_         , "errorType"		  );
		ObjectHandler::validateRange(strike_			, "strike"			  );
		ObjectHandler::validateRange(nominal_			, "nominal"			  );
		ObjectHandler::validateRange(trigger_           , "trigger"		      );

		ObjectHandler::ConvertOper fixedLegTenorOper(*fixedLegTenor_),	// oper conversion
			fixedLegDaycounterOper(*fixedLegDaycounter_),
			floatLegDaycounterOper(*floatLegDaycounter_),
			errorTypeOper(*errorType_),
			strikeOper(*strike_),
			nominalOper(*nominal_);

		QuantLib::Handle<QuantLib::Quote> volatility(					// convert volatility quotation
			boost::shared_ptr<QuantLib::Quote>(
				new QuantLib::SimpleQuote(*volatility_)));

		// index
		OH_GET_REFERENCE(												// 
			index_,
			"index",
			QuantLibAddin::iborIndexObject,
			QuantLib::IborIndex)

		QuantLib::Period fixedLegTenor;
		QuantLib::DayCounter fixedLegDayCounter;
		QuantLib::DayCounter floatLegDayCounter;

		// oper conversion
		if (!fixedLegTenorOper.missing()) {								// fixedLegTenor
		
			fixedLegTenor
				= ObjectHandler::periodFactory()(fixedLegTenorOper);

		}
		else {
		
			fixedLegTenor = QuantLib::Period(6, QuantLib::Months);
		
		}
		
		if (!fixedLegDaycounterOper.missing()) {						// fixedLegDaycounter

			fixedLegDayCounter
				= ObjectHandler::daycountFactory()(fixedLegDaycounterOper);

		}
		else {

			fixedLegDayCounter = QuantLib::ActualActual();

		}

		if (!floatLegDaycounterOper.missing()) {						// floatLegDaycounter

			floatLegDayCounter
				= ObjectHandler::daycountFactory()(floatLegDaycounterOper);

		}
		else {

			floatLegDayCounter = QuantLib::Actual360();

		}

		QuantLib::DayCounter fixedLegDayCounter 
			= ObjectHandler::daycountFactory()(fixedLegDaycounter_);

		QuantLib::DayCounter floatLegDayCounter 
			= ObjectHandler::daycountFactory()(floatLegDaycounter_);

		// termstructure
		OH_GET_REFERENCE(
			termStructurePtr,
			termStructure_,
			QuantLibAddin::YieldTermStructure,
			QuantLib::YieldTermStructure)

		QuantLib::Handle<QuantLib::YieldTermStructure> termStructure(
			termStructurePtr);

		// error type
		QuantLib::CalibrationHelper::CalibrationErrorType errorType =
			QuantLib::CalibrationHelper::ImpliedVolError;

		QuantLib::Real strike								// strike
			= QuantLib::Null<QuantLib::Real>();

		QuantLib::Real nominal								// nominal
			= QuantLib::Null<QuantLib::Real>();

		// value object
		boost::shared_ptr<QuantLibAddin::ValueObjects::swaptionHelperValueObject> swaptionValueObject(
			new QuantLibAddin::ValueObjects::swaptionHelperValueObject(
				objectId_,
                true));
		
		// helper
		boost::shared_ptr<QuantLibAddin::SwaptionHelperObject> bondBootstrapObject(
			new QuantLibAddin::SwaptionHelperObject(
				swaptionValueObject,
				maturity,
				length,
				volatility,
				index,
				fixedLegTenor,
				fixedLegDayCounter,
				floatLegDayCounter,
				termStructure,
				errorType,
				strike,
				nominal));

		std::string returnValue =							// object storage
			ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
			bondBootstrapObject,
			true);

        static XLOPER returnOper;
        ObjectHandler::scalarToOper(returnValue, returnOper);

        return & returnOper;

    } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
            static XLOPER returnOper;
            ObjectHandler::scalarToOper(e.what(), returnOper);

			return & returnOper;

    }

};