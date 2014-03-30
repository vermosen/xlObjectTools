/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef zero_coupon_inflation_swap_united_states_value_object_hpp
#define zero_coupon_inflation_swap_united_states_value_object_hpp

#include <vector>

#include <string>

#include <set>

#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>

#include <oh/valueobject.hpp>

namespace QuantLibAddin { namespace ValueObjects {

    class zeroCouponInflationSwapUnitedStatesValueObject : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

        zeroCouponInflationSwapUnitedStatesValueObject() {}
        
        zeroCouponInflationSwapUnitedStatesValueObject(const std::string & ObjectId,
                        const std::vector<std::string> & LegIDs,
                        const std::vector<std::string> & LegTypes,
                        const std::vector<bool> & Payer,
                        bool Permanent);

        const std::set<std::string> & getSystemPropertyNames() const ;
        
        std::vector<std::string> getPropertyNamesVector() const ;
        
        ObjectHandler::property_t getSystemProperty(const std::string &) const ;
        
        void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char* mPropertyNames[] ;
        
        static std::set<std::string> mSystemPropertyNames ;

        std::vector<std::string> LegIDs_ ;

        std::vector<std::string> LegTypes_ ;

        std::vector<bool> Payer_ ;
        
        bool Permanent_ ;
        
        virtual std::string processorName() { return "InstrumentProcessor" ;}

        template<class Archive>
        void serialize(Archive & ar, const unsigned int) {
        
            boost::serialization::void_cast_register<zeroCouponInflationSwapUnitedStatesValueObject, ObjectHandler::ValueObject>(this, this) ;
            ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                & boost::serialization::make_nvp("ClassName", className_)
                & boost::serialization::make_nvp("LegIDs", LegIDs_)
                & boost::serialization::make_npv("LegTypes", legTypes_)
                & boost::serialization::make_nvp("Payer", Payer_)
                & boost::serialization::make_nvp("Permanent", Permanent_)
                & boost::serialization::make_nvp("UserProperties", userProperties) ;

        } ;

    } ;

} }

#endif