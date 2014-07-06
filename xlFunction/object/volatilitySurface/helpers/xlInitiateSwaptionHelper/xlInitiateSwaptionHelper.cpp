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
											const char * maturity_,
											const char * length_,
											const double * volatility_,
											const char * index_,
											const char * fixedLegTenor_,
											const char * fixedLegDaycounter_,
											const char * floatLegDaycounter_,
											const char * termStructure_,
											const xloper * errorType_,
											const xloper * strike_,
											const xloper * nominal_,
                                            const xloper * trigger_) {
    
   boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateSwaptionHelper"));

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

		ObjectHandler::validateRange(errorType_, "errorType");			// validate range
		ObjectHandler::validateRange(strike_, "strike");
		ObjectHandler::validateRange(nominal_, "nominal");
		ObjectHandler::validateRange(trigger_, "trigger");

		ObjectHandler::ConvertOper myOper1(*errorType_),				// oper conversion
			myOper2(*strike_),
			myOper3(*nominal_);

		QuantLib::Period maturity										// cpp data
			= ObjectHandler::periodFactory()(maturity_);

		QuantLib::Period length 
			= ObjectHandler::periodFactory()(length_);

		QuantLib::Handle<QuantLib::Quote> volatility(
			boost::shared_ptr<QuantLib::Quote>(
				new QuantLib::SimpleQuote(*volatility_)));

		// index
		OH_GET_REFERENCE(
			index,
			"index",
			QuantLibAddin::iborIndexObject,
			QuantLib::IborIndex)

		// tenors and dc
		QuantLib::Period fixedLegTenor 
		= ObjectHandler::periodFactory()(fixedLegTenor_);

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