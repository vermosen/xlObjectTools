/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef fixed_leg_australia_value_object_hpp
#define fixed_leg_australia_value_object_hpp

#include <vector>

#include <string>

#include <set>

#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>

#include <oh/valueobject.hpp>

namespace QuantLibAddin { namespace ValueObjects {

    class fixedLegAustraliaValueObject : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

        fixedLegAustraliaValueObject() {} ;

        fixedLegAustraliaValueObject(const std::string & ObjectId,
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
                                     double notional) ;

        const std::set<std::string>& getSystemPropertyNames() const ;

        std::vector<std::string> getPropertyNamesVector() const ;

        ObjectHandler::property_t getSystemProperty(const std::string &) const ;

        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char * mPropertyNames[] ;

        static std::set<std::string> mSystemPropertyNames ;

        bool permanent_ ;
        
        double effectiveDate_ ;
        
        double firstCouponDate_ ;
        
        double lastCouponDate_ ;
        
        double maturityDate_ ;
        
        long paymentConvention_ ;
        
        long terminationPaymentConvention_ ;
        
        bool endOfMonth_ ;
        
        double fixedCouponRate_ ;
        
        double notional_ ;

        long frequency_ ;

        std::string daycounter_ ;

        long compounding_ ;

        template<class Archive>
        void serialize(Archive& ar, const unsigned int) {

        boost::serialization::void_cast_register<fixedLegAustraliaValueObject, ObjectHandler::ValueObject>(this, this) ;

            ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                & boost::serialization::make_nvp("ClassName", className_)
                & boost::serialization::make_nvp("effectiveDate", effectiveDate_)
                & boost::serialization::make_nvp("firstCouponDate", firstCouponDate_)
                & boost::serialization::make_nvp("lastCouponDate", lastCouponDate_)
                & boost::serialization::make_nvp("maturityDate", maturityDate_)
                & boost::serialization::make_nvp("paymentConvention", paymentConvention_)
                & boost::serialization::make_nvp("terminationPaymentConvention", terminationPaymentConvention_)
                & boost::serialization::make_nvp("endOfMonth", endOfMonth_)
                & boost::serialization::make_nvp("fixedCouponRate", fixedCouponRate_)
                & boost::serialization::make_nvp("notional", notional_)
                & boost::serialization::make_nvp("Permanent", permanent_)
                & boost::serialization::make_nvp("frequency", frequency_)
                & boost::serialization::make_nvp("daycounter", daycounter_)
                & boost::serialization::make_nvp("compounding", compounding_)
                & boost::serialization::make_nvp("User Properties", userProperties) ;

            } ;

        } ;

    }

}

#endif