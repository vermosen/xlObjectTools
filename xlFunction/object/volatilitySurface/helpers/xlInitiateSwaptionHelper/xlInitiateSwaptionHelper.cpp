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

		OH_GET_REFERENCE(												// index
			indexPtr,
			index_,
			QuantLibAddin::iborIndexObject,
			QuantLib::IborIndex)

		OH_GET_REFERENCE(												// curve
			termStructurePtr,
			termStructure_,
			QuantLibAddin::YieldTermStructure,
			QuantLib::YieldTermStructure)

		QuantLib::Handle<QuantLib::YieldTermStructure> termStructure(	// create the handle
			termStructurePtr);

		QuantLib::Period fixedLegTenor;									// QL types
		QuantLib::DayCounter fixedLegDayCounter;
		QuantLib::DayCounter floatLegDayCounter;
		QuantLib::SwaptionHelper::CalibrationErrorType errorType;
		QuantLib::Real strike;
		QuantLib::Real nominal;
		
		// xloper conversions
		if (!fixedLegTenorOper.missing())								// fixedLegTenor
			fixedLegTenor
				= ObjectHandler::periodFactory()(fixedLegTenorOper);
		else 
			fixedLegTenor 
				= QuantLib::Period(6, QuantLib::Months);
		
		if (!fixedLegDaycounterOper.missing())							// fixedLegDaycounter
			fixedLegDayCounter
				= ObjectHandler::daycountFactory()(fixedLegDaycounterOper);
		else
			fixedLegDayCounter 
				= QuantLib::ActualActual(QuantLib::ActualActual::ISDA);

		if (!floatLegDaycounterOper.missing())							// floatLegDaycounter
			floatLegDayCounter
			= ObjectHandler::daycountFactory()(floatLegDaycounterOper);
		else
			floatLegDayCounter = QuantLib::Actual360();

		if (!errorTypeOper.missing())									// errorType
			errorType													// ugly one <- would need a factory here
			= static_cast<QuantLib::SwaptionHelper::CalibrationErrorType>((long)errorTypeOper);
		else
			errorType = QuantLib::SwaptionHelper::RelativePriceError;

		(strikeOper.missing() ?											// strike
			strike = QuantLib::Null<QuantLib::Real>() :
			strike = strikeOper);

		(nominalOper.missing() ?										// nominal
			nominal = QuantLib::Null<QuantLib::Real>() :
			nominal = nominalOper);

																		// value object
		boost::shared_ptr<QuantLibAddin::ValueObjects::swaptionHelperValueObject> swaptionValueObject(
			new QuantLibAddin::ValueObjects::swaptionHelperValueObject(
				objectId_,
                true));
		
																		// swaption object
		boost::shared_ptr<QuantLibAddin::SwaptionHelperObject> swaptionObject(
			new QuantLibAddin::SwaptionHelperObject(
				swaptionValueObject,
				QuantLib::Date(static_cast<QuantLib::BigInteger>(*maturity_)),
				QuantLib::Date(static_cast<QuantLib::BigInteger>(*length_)),
				volatility,
				indexPtr,
				fixedLegTenor,
				fixedLegDayCounter,
				floatLegDayCounter,
				termStructure,
				errorType,
				strike,
				nominal));

		std::string returnValue =										// object storage
			ObjectHandler::RepositoryXL::instance().storeObject(
				objectId_,
				swaptionObject,
				true);

        static XLOPER returnOper;										// return oper
        ObjectHandler::scalarToOper(returnValue, returnOper);
        return & returnOper;

    } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
            static XLOPER returnOper;
            ObjectHandler::scalarToOper(e.what(), returnOper);
			return & returnOper;

    }

};