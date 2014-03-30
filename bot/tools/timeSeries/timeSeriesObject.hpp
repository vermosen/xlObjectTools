/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef time_series_object_hpp
#define time_series_object_hpp

#include <oh/libraryobject.hpp>

#include <ql/timeseries.hpp>

#include <bot/tools/TimeSeries/timeSeriesValueObject.hpp>

namespace QuantLibAddin {

template <class T, class Container = std::map<QuantLib::Date, T>>
    class TimeSeriesObject : public ObjectHandler::LibraryObject<QuantLib::TimeSeries<T, Container>> {

    public :

        TimeSeriesObject(boost::shared_ptr<QuantLibAddin::ValueObjects::TimeSeriesValueObject> & valueObject,
                                           QuantLib::TimeSeries<T, Container> timeSerie,
                                           bool permanent) ;


        } ;

template <class T, class Container> 
    TimeSeriesObject<T, Container>::TimeSeriesObject(boost::shared_ptr<QuantLibAddin::ValueObjects::TimeSeriesValueObject> & valueObject,
                                                     const QuantLib::TimeSeries<T, Container> timeSeries,
                                                     bool permanent) : 
    
        ObjectHandler::LibraryObject<QuantLib::TimeSeries<T, Container>>(valueObject, permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::TimeSeries<T, Container>> (new
                QuantLib::TimeSeries<T, Container>(timeSeries)) ;

    }
        
}
#endif