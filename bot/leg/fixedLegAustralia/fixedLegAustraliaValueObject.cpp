/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/leg/fixedLegAustralia/fixedLegAustraliaValueObject.hpp>

namespace QuantLibAddin { namespace ValueObjects {

    const char * fixedLegAustraliaValueObject::mPropertyNames[] = {
        // The two values below are not desired in the return value of ohObjectPropertyNames().
        // For now we just comment them out as this seems not to break anything.
        //"ClassName",
        "ObjectId",
        "effectiveDate",
        "firstCouponDate",
        "lastCouponDate",
        "maturityDate",
        "paymentConvention",
        "terminationPaymentConvention",
        "permanent",
        "endOfMonth",
        "fixedCouponRate",
        "frequency",
        "daycounter",
        "compounding",
        "notional"


    } ;

    std::set<std::string> fixedLegAustraliaValueObject::mSystemPropertyNames(
        mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*)) ;

    const std::set<std::string>& fixedLegAustraliaValueObject::getSystemPropertyNames() const {

        return mSystemPropertyNames ;

    }

    std::vector<std::string> fixedLegAustraliaValueObject::getPropertyNamesVector() const {

        std::vector<std::string> ret(
            mPropertyNames, mPropertyNames + sizeof(mPropertyNames) / sizeof(const char*)) ;
        for (std::map<std::string, ObjectHandler::property_t>::const_iterator i = userProperties.begin() ;
            i != userProperties.end() ; ++i)
            ret.push_back(i->first) ;
        return ret ;

    }

    ObjectHandler::property_t fixedLegAustraliaValueObject::getSystemProperty(const std::string & name) const {
        std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

        if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

            return objectId_ ;

        else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

            return className_ ;

        else if(strcmp(nameUpper.c_str(), "EFFECTIVEDATE") == 0)

            return effectiveDate_ ;

        else if(strcmp(nameUpper.c_str(), "FIRSTCOUPONDATE") == 0)

            return firstCouponDate_ ;

        else if(strcmp(nameUpper.c_str(), "LASTCOUPONDATE") == 0)

            return lastCouponDate_ ;

        else if(strcmp(nameUpper.c_str(), "MATURITYDATE") == 0)

            return maturityDate_ ;

        else if(strcmp(nameUpper.c_str(), "PAYMENTCONVENTION") == 0)
        
            return paymentConvention_ ;
        
        else if(strcmp(nameUpper.c_str(), "TERMINATIONPAYMENTCONVENTION") == 0)
        
            return terminationPaymentConvention_ ;

        else if(strcmp(nameUpper.c_str(), "ENDOFMONTH") == 0)
            
            return endOfMonth_ ;

        else if(strcmp(nameUpper.c_str(), "FIXEDCOUPONRATE") == 0)
            
            return fixedCouponRate_ ;

        else if(strcmp(nameUpper.c_str(), "NOTIONAL") == 0)
            
            return notional_ ;

        else if(strcmp(nameUpper.c_str(), "FREQUENCY") == 0)
            
            return frequency_ ;

        else if(strcmp(nameUpper.c_str(), "DAYCOUNTER") == 0)
            
            return daycounter_ ;

        else if(strcmp(nameUpper.c_str(), "COMPOUNDING") == 0)
            
            return compounding_ ;

        else

            OH_FAIL("Error: attempt to retrieve non-existent Property: '" + name + "'") ;

    }

    void fixedLegAustraliaValueObject::setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) {

        std::string nameUpper = boost::algorithm::to_upper_copy(name) ;

        if(strcmp(nameUpper.c_str(), "OBJECTID") == 0)

            objectId_ = boost::get<std::string>(value) ;

        else if(strcmp(nameUpper.c_str(), "CLASSNAME") == 0)

            className_ = boost::get<std::string>(value) ;

        else if(strcmp(nameUpper.c_str(), "EFFECTIVEDATE") == 0)

            effectiveDate_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "FIRSTCOUPONDATE") == 0)

            firstCouponDate_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "LASTCOUPONDATE") == 0)

            lastCouponDate_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "MATURITYDATE") == 0)

            maturityDate_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "PAYMENTCONVENTION") == 0)

            paymentConvention_ = ObjectHandler::convert2<long>(value) ;

        else if(strcmp(nameUpper.c_str(), "TERMINATIONPAYMENTCONVENTION") == 0)

           terminationPaymentConvention_ = ObjectHandler::convert2<long>(value) ;

        else if(strcmp(nameUpper.c_str(), "ENDOFMONTH") == 0)

            endOfMonth_ = ObjectHandler::convert2<bool>(value) ;

        else if(strcmp(nameUpper.c_str(), "FIXEDCOUPONRATE") == 0)

            fixedCouponRate_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "NOTIONAL") == 0)

            notional_ = ObjectHandler::convert2<double>(value) ;

        else if(strcmp(nameUpper.c_str(), "FREQUENCY") == 0)

            frequency_ = ObjectHandler::convert2<long>(value) ;

        else if(strcmp(nameUpper.c_str(), "DAYCOUNTER") == 0)

            daycounter_ = boost::get<std::string>(value) ;

        else if(strcmp(nameUpper.c_str(), "COMPOUNDING") == 0)

            notional_ = ObjectHandler::convert2<long>(value) ;

        else if(strcmp(nameUpper.c_str(), "PERMANENT") == 0)

            permanent_ = ObjectHandler::convert2<bool>(value) ;

        else

            OH_FAIL("Error: attempt to set non-existent Property: '" + name + "'") ;
    }

        /* constructeur */
    fixedLegAustraliaValueObject::fixedLegAustraliaValueObject(
            const std::string & ObjectId,
            const bool permanent, 
            double effectiveDate,
            double firstCouponDate,
            double lastCouponDate,
            double maturityDate,
            long paymentConvention,
            long terminationPaymentConvention,
            bool endOfMonth,
            double fixedCouponRate,
            long frequency,
            const std::string & daycounter,
            long compounding,
            double notional) :

        ObjectHandler::ValueObject(ObjectId, "fixedLegAustraliaValueObject", permanent),
        permanent_(permanent), 
        effectiveDate_(effectiveDate),
        firstCouponDate_(firstCouponDate),
        lastCouponDate_(lastCouponDate),
        maturityDate_(maturityDate),
        paymentConvention_(paymentConvention),
        terminationPaymentConvention_(terminationPaymentConvention),
        endOfMonth_(endOfMonth),
        fixedCouponRate_(fixedCouponRate),
        frequency_(frequency),
        daycounter_(daycounter),
        compounding_(compounding),
        notional_(notional) {}

    }

}