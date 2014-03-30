/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/12/10
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef interpolated_curve_value_object_hpp
#define interpolated_curve_value_object_hpp


#include <vector>

#include <string>

#include <set>


#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>


#include <oh/valueobject.hpp>


namespace QuantLibAddin { namespace ValueObjects {

    class interpolatedCurveValueObject : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

       inline interpolatedCurveValueObject() {} ;

       interpolatedCurveValueObject(const std::string & ObjectId,
                                    const ObjectHandler::property_t & calculationDate,
                                    bool permanent) ;

        const std::set<std::string>& getSystemPropertyNames() const ;

        std::vector<std::string> getPropertyNamesVector() const ;
        
        ObjectHandler::property_t getSystemProperty(const std::string &) const ;
        
        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char * mPropertyNames[] ;
        
        static std::set<std::string> mSystemPropertyNames ;

        ObjectHandler::property_t calculationDate_ ;
        
        bool permanent_ ;


        template<class Archive>
        void serialize(Archive & ar, const unsigned int) {
        
                boost::serialization::void_cast_register<interpolatedCurveValueObject, ObjectHandler::ValueObject>(this, this) ;

                ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                    & boost::serialization::make_nvp("ClassName", className_)
                    & boost::serialization::make_nvp("calculationDate", calculationDate_)
                    & boost::serialization::make_nvp("permanent", permanent_)
                    & boost::serialization::make_nvp("UserProperties", userProperties) ;

            } ;


        } ;

    } }

#endif
