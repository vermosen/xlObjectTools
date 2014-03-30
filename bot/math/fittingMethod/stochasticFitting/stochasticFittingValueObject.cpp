/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingValueObject.hpp>


namespace QuantLibAddin { namespace ValueObjects {

        /* constructeur */
    stochasticFittingValueObject::stochasticFittingValueObject(const std::string & ObjectId,
                                                                               const bool & permanent) :

            ObjectHandler::ValueObject(ObjectId, "stochasticFittingValueObject", permanent),
            permanent_(permanent) {}

    const char * stochasticFittingValueObject::mPropertyNames[] = {

                // The two values below are not desired in the return value of ohObjectPropertyNames().
                // For now we just comment them out as this seems not to break anything.
            "ClassName",
            "ObjectId"


        } ;

    std::set<std::string> stochasticFittingValueObject::mSystemPropertyNames(
        mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*)) ;

    const std::set<std::string> & stochasticFittingValueObject::getSystemPropertyNames() const {


            return mSystemPropertyNames ;


        }


    std::vector<std::string> stochasticFittingValueObject::getPropertyNamesVector() const {

            std::vector<std::string> ret(mPropertyNames, 
                                         mPropertyNames + sizeof(mPropertyNames) / sizeof(const char *)) ;

            for (std::map<std::string, ObjectHandler::property_t>::const_iterator i = userProperties.begin() ;
                i != userProperties.end() ; ++i) ret.push_back(i->first) ;

            return ret ;

        }

    ObjectHandler::property_t stochasticFittingValueObject::getSystemProperty(const std::string & name) const {

            std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

            if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

                return objectId_ ;

            else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

                return className_ ;

            else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)

                return permanent_ ;

            else

                OH_FAIL("Error: attempt to retrieve non-existent Property: '" + name + "'") ;

    }

    void stochasticFittingValueObject::setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) {

            std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

            if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

                objectId_ = boost::get<std::string>(value) ;

            else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

                className_ = boost::get<std::string>(value) ;

            else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)

                permanent_ = ObjectHandler::convert2<bool>(value) ;

            else

                OH_FAIL("Error: attempt to set non-existent Property: '" + name + "'") ;

        } ;

    }

}