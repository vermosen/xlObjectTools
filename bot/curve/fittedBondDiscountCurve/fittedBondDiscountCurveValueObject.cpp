/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/12/10
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveValueObject.hpp>


namespace QuantLibAddin { namespace ValueObjects {

    const char * fittedBondDiscountCurveValueObject::mPropertyNames[] = {
        // The two values below are not desired in the return value of ohObjectPropertyNames().
        // For now we just comment them out as this seems not to break anything.
        //"ClassName",
        //"ObjectId",
        "settlementDate"

    } ;

    std::set<std::string> fittedBondDiscountCurveValueObject::mSystemPropertyNames(
        mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*)) ;

    const std::set<std::string> & fittedBondDiscountCurveValueObject::getSystemPropertyNames() const {

        return mSystemPropertyNames ;

    }

    std::vector<std::string> fittedBondDiscountCurveValueObject::getPropertyNamesVector() const {

        std::vector<std::string> ret(
            mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*)) ;
        for (std::map<std::string, ObjectHandler::property_t>::const_iterator i = userProperties.begin() ;
            i != userProperties.end() ; ++i)
            ret.push_back(i->first) ;
        return ret ;

    }

    ObjectHandler::property_t fittedBondDiscountCurveValueObject::getSystemProperty(const std::string & name) const {
        std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

        if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

            return objectId_ ;

        else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

            return className_ ;

        else if(strcmp(nameUpper.c_str(), "SETTLEMENTDATE") == 0)

            return settlementDate_ ;

        else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)

            return permanent_ ;

        else

            OH_FAIL("Error: attempt to retrieve non-existent Property: '" + name + "'") ;

    }

    void fittedBondDiscountCurveValueObject::setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) {

        std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

        if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

            objectId_ = boost::get<std::string>(value) ;

        else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

            className_ = boost::get<std::string>(value) ;

        else if(strcmp(nameUpper.c_str(), "SETTLEMENTDATE") == 0)

            settlementDate_ = ObjectHandler::vector::convert2<ObjectHandler::property_t>(value, nameUpper) ;

        else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)

            permanent_ = ObjectHandler::convert2<bool>(value) ;

        else

            OH_FAIL("Error: attempt to set non-existent Property: '" + name + "'") ;
    }

        /* constructeur */
   fittedBondDiscountCurveValueObject::fittedBondDiscountCurveValueObject(
            const std::string & ObjectId,
            const ObjectHandler::property_t & settlementDate,
            bool permanent) :

        ObjectHandler::ValueObject(ObjectId, "fittedBondDiscountCurveValueObject", permanent),
        settlementDate_(settlementDate),
        permanent_(permanent) {}

    }

} ;
