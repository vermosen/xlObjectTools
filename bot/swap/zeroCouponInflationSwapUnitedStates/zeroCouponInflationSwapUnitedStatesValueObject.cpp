/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/swap/zeroCouponInflationSwapUnitedStates/zeroCouponInflationSwapUnitedStatesValueObject.hpp>

namespace QuantLibAddin { namespace ValueObjects {

    const char * zeroCouponInflationSwapUnitedStatesValueObject::mPropertyNames[] = {
        // The two values below are not desired in the return value of ohObjectPropertyNames().
        // For now we just comment them out as this seems not to break anything.
        //"ClassName",
        //"ObjectId",
        "LegIDs",
        "LegTypes",
        "Payer",
        "Permanent"


    } ;

    std::set<std::string> zeroCouponInflationSwapUnitedStatesValueObject::mSystemPropertyNames(
        mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char *)) ;

    const std::set<std::string>& zeroCouponInflationSwapUnitedStatesValueObject::getSystemPropertyNames() const {
        return mSystemPropertyNames;
    }

    std::vector<std::string> zeroCouponInflationSwapUnitedStatesValueObject::getPropertyNamesVector() const {
        std::vector<std::string> ret(
            mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*));
        for (std::map<std::string, ObjectHandler::property_t>::const_iterator i = userProperties.begin();
            i != userProperties.end(); ++i)
            ret.push_back(i->first);
        return ret;
    }

    ObjectHandler::property_t zeroCouponInflationSwapUnitedStatesValueObject::getSystemProperty(const std::string& name) const {
        std::string nameUpper = boost::algorithm::to_upper_copy(name);
        if(strcmp(nameUpper.c_str(), "OBJECTID")==0)
            return objectId_;
        else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)
            return className_;
        else if(strcmp(nameUpper.c_str(), "LEGIDS") == 0)
            return LegIDs_;
        else if(strcmp(nameUpper.c_str(), "LEGTYPES") == 0)
            return LegTypes_;
        else if(strcmp(nameUpper.c_str(), "PAYER") == 0)
            return Payer_;
        else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)
            return Permanent_;
        else
            OH_FAIL("Error: attempt to retrieve non-existent Property: '" + name + "'");
    }

    void zeroCouponInflationSwapUnitedStatesValueObject::setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) {
        std::string nameUpper = boost::algorithm::to_upper_copy(name);
        if(strcmp(nameUpper.c_str(), "OBJECTID")==0)
            objectId_ = boost::get<std::string>(value);
        else if(strcmp(nameUpper.c_str(), "CLASSNAME")==0)
            className_ = boost::get<std::string>(value);
        else if(strcmp(nameUpper.c_str(), "LEGIDS")==0)
            LegIDs_ = ObjectHandler::vector::convert2<std::string>(value, nameUpper) ;
        else if(strcmp(nameUpper.c_str(), "LEGTYPES")==0)
            LegTypes_ = ObjectHandler::vector::convert2<std::string>(value, nameUpper) ;
        else if(strcmp(nameUpper.c_str(), "PAYER")==0)
            Payer_ = ObjectHandler::vector::convert2<bool>(value, nameUpper) ;
        else if(strcmp(nameUpper.c_str(), "PERMANENT")==0)
            Permanent_ = ObjectHandler::convert2<bool>(value) ;
        else
            OH_FAIL("Error: attempt to set non-existent Property: '" + name + "'") ;
    }

    zeroCouponInflationSwapUnitedStatesValueObject::zeroCouponInflationSwapUnitedStatesValueObject(
            const std::string & ObjectId,
            const std::vector<std::string> & LegIDs,
            const std::vector<std::string> & LegTypes,
            const std::vector<bool> & Payer,
            bool Permanent) :
        ObjectHandler::ValueObject(ObjectId, "zeroCouponInflationSwapUnitedStatesValueObject", Permanent),
        LegIDs_(LegIDs),
        LegTypes_(LegTypes),
        Payer_(Payer),
        Permanent_(Permanent) {
                  
            for (std::vector<std::string>::const_iterator i = LegIDs.begin() ;

                    i != LegIDs.end() ; ++i) processPrecedentID(*i) ;
                
                }

    } 

}