/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlFunction/object/math/xlInitiateTimeSeries/xlInitiateTimeSeries.hpp"

// registers a time series object
DLLEXPORT char * xlInitiateTimeSeries (const char * objectID_,
                                       const xloper * date_,
                                       const xloper * data_,
                                       xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateTimeSeries")) ;

	try {


		QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

		ObjectHandler::validateRange(trigger_, "trigger") ;	// validate range

		std::vector<double> tempDate						// convert xlOper
			= ObjectHandler::operToVector<double>(
				* date_, "tempdates") ;

		std::vector<double> tempData 
			= ObjectHandler::operToVector<double>(
				* data_, "tempdata") ;

		QL_REQUIRE(tempDate.size() == tempData.size(), "unapropriate data set") ;

		// if the data set is not sorted we 
		// first sort before creating the time series
		std::vector<QuantLib::Date> date;
		std::vector<double> data;

		for (unsigned long i = 0 ; i < tempDate.size() ; i++)

			if (tempDate[i] != 0.0) {
                        
				date.push_back(QuantLib::Date(static_cast<QuantLib::BigInteger>(tempDate[i]))) ;
				data.push_back(tempData[i]) ;

			}

		QuantLib::TimeSeries<double> myTempSeries(		// create a first time series
			date.begin(), 
			date.end(), 
			data.begin());

		std::sort(date.begin(), date.end());			// sort the dates

		data.clear();									// clears existing data

		for (std::vector<QuantLib::Date>::iterator It = date.begin(); It != date.end(); ++It)
			data.push_back(myTempSeries[* It]) ;

		QuantLib::TimeSeries<QuantLib::Real> finalSeries(
			date.begin(), 
			date.end(), 
			data.begin());

		// build the value object
		boost::shared_ptr<QuantLibAddin::ValueObjects::TimeSeriesValueObject> myTimeSeriesValueObject(
		new QuantLibAddin::ValueObjects::TimeSeriesValueObject(objectID_,
																"double",
																true));

		// creates the series
		boost::shared_ptr<QuantLibAddin::TimeSeriesObject<QuantLib::Real>> myTimeSeriesObject(
			new QuantLibAddin::TimeSeriesObject<QuantLib::Real>(myTimeSeriesValueObject,
																finalSeries,
																true)) ;

		// object storage, enforce rewriting
		std::string returnValue =
			ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
																myTimeSeriesObject, 
																true);

		static char ret[XL_MAX_STR_LEN] ;
		ObjectHandler::stringToChar(returnValue, ret) ;
		return ret ;

    } catch (std::exception & e) {

        static char ret[XL_MAX_STR_LEN] ;
        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
        ObjectHandler::stringToChar(e.what(), ret) ;
        return ret ;

    }

} ;
