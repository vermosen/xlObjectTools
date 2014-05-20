/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/index/xlInitiateOvernightIndex/xlInitiateOvernightIndex.hpp>

	/* registers an overnight index */
DLLEXPORT char * xlInitiateOvernightIndex (const char * objectId_,
                                           const xloper * indexHistoryId_,
                                           const xloper * settlementDays_,
                                           const char * fixingCalendar_,
                                           const char * dayCounter_,
                                           const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateOvernightIndex"));

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

        ObjectHandler::validateRange(trigger_       , "trigger"         );	// validate range
		ObjectHandler::validateRange(indexHistoryId_, "index History Id");
		ObjectHandler::validateRange(settlementDays_, "settlement Days" );

        ObjectHandler::ConvertOper myOper1(* indexHistoryId_),				// convert xlOper
								   myOper2(* settlementDays_);


        QuantLib::Natural settlementDays(
            myOper2.missing() ? 0 : 
            static_cast<long>(myOper2)) ;

		boost::shared_ptr<QuantLib::TimeSeries<QuantLib::Real> > myTimeSeriesPtr ;

		if (myOper1.missing()) {											// obtain fixing time series
			
			myTimeSeriesPtr = 
				boost::shared_ptr<QuantLib::TimeSeries<QuantLib::Real> >(
					new QuantLib::TimeSeries<QuantLib::Real>());
			
		} 
			
		else {
			
			OH_GET_REFERENCE(tempPtr,
				static_cast<std::string>(myOper1),
				QuantLibAddin::TimeSeriesObject<QuantLib::Real>,
				QuantLib::TimeSeries<QuantLib::Real>)

				myTimeSeriesPtr = tempPtr;									// necessary otherwise crashes
			
		}

		// value object
		boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> valueObject(
			new QuantLibAddin::ValueObjects::overnightIndexValueObject);

		// instanciate the object
        boost::shared_ptr<QuantLibAddin::overnightIndexObject> myIndex(
            new QuantLibAddin::overnightIndexObject(valueObject,
                                                    objectId_,
                                                    settlementDays,
                                                    ObjectHandler::calendarFactory()(fixingCalendar_),
                                                    ObjectHandler::daycountFactory()(dayCounter_),
                                                    QuantLib::RelinkableHandle<QuantLib::YieldTermStructure>(),
                                                    true));

		myIndex->addFixings(myTimeSeriesPtr->dates(),						// insert fixing
                            myTimeSeriesPtr->values(),
                            true,
                            true);

        std::string returnValue =											// object storage
            ObjectHandler::RepositoryXL::instance().storeObject(
				std::string(objectId_),
				myIndex,
                true);

        static char ret[XL_MAX_STR_LEN];
        ObjectHandler::stringToChar(returnValue, ret);
        return ret;

    } catch (std::exception & e) {

        static char ret[XL_MAX_STR_LEN];
        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        ObjectHandler::stringToChar(e.what(), ret);
        return ret;

    }

};
