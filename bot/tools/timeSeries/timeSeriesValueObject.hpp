/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef time_series_value_object_hpp
#define time_series_value_object_hpp

#include <oh/valueobject.hpp>

#include <vector>

#include <string>

#include <set>

#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>


namespace QuantLibAddin { namespace ValueObjects {

    class TimeSeriesValueObject : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

        inline TimeSeriesValueObject() {} ;

        TimeSeriesValueObject(const std::string & ObjectId,
                              const std::string & dataType,
                              bool permanent) ;

        const std::set<std::string>& getSystemPropertyNames() const ;
        std::vector<std::string> getPropertyNamesVector() const ;
        ObjectHandler::property_t getSystemProperty(const std::string &) const ;
        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char * mPropertyNames[] ;
        static std::set<std::string> mSystemPropertyNames ;

        std::string dataType_ ;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int) {
        boost::serialization::void_cast_register<TimeSeriesValueObject, ObjectHandler::ValueObject>(this, this) ;

            ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                & boost::serialization::make_nvp("ClassName", className_)
                & boost::serialization::make_nvp("dataType", dataType_)
                & boost::serialization::make_nvp("permanent", permanent_)
                & boost::serialization::make_nvp("UserProperties", userProperties) ;

            } ;

        } ;

    }

}

#endif