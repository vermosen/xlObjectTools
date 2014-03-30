/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef bot_matrix_value_object_hpp
#define bot_matrix_value_object_hpp

#include <oh/valueobject.hpp>

#include <vector>
#include <string>
#include <set>

#include <boost/serialization/map.hpp>
#include <boost/algorithm/string/case_conv.hpp>


namespace QuantLibAddin { namespace ValueObjects {


    class matrixValueObject : public ObjectHandler::ValueObject {


        friend class boost::serialization::access ;


    public :


        inline matrixValueObject() {} ;

        matrixValueObject(const std::string & ObjectId,
                          const bool & permanent) ;

        const std::set<std::string>& getSystemPropertyNames() const ;

        std::vector<std::string> getPropertyNamesVector() const ;

        ObjectHandler::property_t getSystemProperty(const std::string & property_t) const ;

        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;


    protected :


        static const char * mPropertyNames[] ;

        static std::set<std::string> mSystemPropertyNames ;

        bool permanent_ ;
        
        bool assumeSquare_ ;


        template<class Archive>
        
        void serialize(Archive& ar, const unsigned int) {
        
        boost::serialization::void_cast_register<MatrixValueObject, ObjectHandler::ValueObject>(this, this) ;


            ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                & boost::serialization::make_nvp("ClassName", className_)
                & boost::serialization::make_nvp("permanent", permanent_)
                & boost::serialization::make_nvp("UserProperties", userProperties) ;


            } ;


        } ;


    }


}


#endif