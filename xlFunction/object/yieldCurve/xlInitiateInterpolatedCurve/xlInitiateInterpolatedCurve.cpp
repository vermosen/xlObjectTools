/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/yieldCurve/xlInitiateInterpolatedCurve/xlInitiateInterpolatedCurve.hpp>

	// register an interpolated curve object
DLLEXPORT char * xlInitiateInterpolatedCurve(const char * objectID_       ,
                                             xloper     * calculationDate_,
                                             const char * curveCalendarId_,
                                             xloper     * helperId_       ,
                                             xloper     * trigger_         ) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateInterpolatedCurve")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // range validation
        ObjectHandler::validateRange(trigger_        , "trigger"         );
        ObjectHandler::validateRange(helperId_       , "helper Id"       );
        ObjectHandler::validateRange(calculationDate_, "calculation Date");
            
        ObjectHandler::ConvertOper myOper1(* calculationDate_) ;	// xlopers

        std::vector<std::string> helperId = ObjectHandler::operToVector<std::string>(
            * helperId_, "helper Id") ;

        QuantLib::Date currentDate(									// initiate pricing date
            myOper1.missing() ? 
            QuantLib::Date() : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1)));

        std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<	// the helpers
			QuantLib::YieldTermStructure> > > helpers;

        for (std::vector<std::string>::const_iterator It = helperId.begin();
			It != helperId.end(); ++It) {

            OH_GET_REFERENCE(helperPtr, * It,						// get helper references
                             QuantLibAddin::RateHelper, 
                             QuantLib::RateHelper);

			helpers.push_back(helperPtr);

        }

            // Construction du value object
        boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedCurveValueObject> curveValueObject(
            new QuantLibAddin::ValueObjects::interpolatedCurveValueObject(
                objectID_,
                currentDate.serialNumber(),
                true)) ;

            // creates the curve
        boost::shared_ptr<ObjectHandler::Object> myCurve(
            new QuantLibAddin::interpolatedCurveObject(
				curveValueObject,
                currentDate,
				helpers, true,
                std::vector<QuantLib::Handle<QuantLib::Quote> >(),	// empty jump date
                std::vector<QuantLib::Date>(),
                CURVE_DEFAULT_ACCURACY));

		    // object storage
	    std::string returnValue =
            ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                myCurve, 
                                                                true);

        static char ret[XL_MAX_STR_LEN] ;
        ObjectHandler::stringToChar(returnValue, ret);
        return ret;

    } catch (std::exception & e) {

        static char ret[XL_MAX_STR_LEN];
        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        ObjectHandler::stringToChar(e.what(), ret);
        return ret;

    }

} ;
