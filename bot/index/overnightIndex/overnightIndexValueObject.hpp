/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef overnight_index_value_object_hpp
#define overnight_index_value_object_hpp

#include <oh/valueobject.hpp>

#include <vector>

#include <string>

#include <set>

#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>


namespace QuantLibAddin { namespace ValueObjects {

    class overnightIndexValueObject : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

        inline overnightIndexValueObject() {} ;

        overnightIndexValueObject(const std::string & ObjectId,
                                      bool permanent) ;

        const std::set<std::string>& getSystemPropertyNames() const ;
        std::vector<std::string> getPropertyNamesVector() const ;
        ObjectHandler::property_t getSystemProperty(const std::string &) const ;
        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char * mPropertyNames[] ;
        static std::set<std::string> mSystemPropertyNames ;

        template<class Archive>
        void serialize(Archive & ar, const unsigned int) {

                boost::serialization::void_cast_register<overnightIndexValueObject, ObjectHandler::ValueObject>(this, this) ;

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