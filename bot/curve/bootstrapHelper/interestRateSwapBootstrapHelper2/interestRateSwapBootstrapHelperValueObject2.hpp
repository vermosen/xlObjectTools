/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef interest_rate_swap_bootstrap_helper_value_object2
#define interest_rate_swap_bootstrap_helper_value_object2

#include <vector>

#include <string>

#include <set>


#include <boost/serialization/map.hpp>

#include <boost/algorithm/string/case_conv.hpp>


#include <oh/valueobject.hpp>


namespace QuantLibAddin { namespace ValueObjects {

    class interestRateSwapBootstrapHelperValueObject2 : public ObjectHandler::ValueObject {

        friend class boost::serialization::access ;

    public :

        inline interestRateSwapBootstrapHelperValueObject2() {} ;

        interestRateSwapBootstrapHelperValueObject2(const std::string & ObjectId,
                                                    const bool permanent) ;

        const std::set<std::string>& getSystemPropertyNames() const ;
        std::vector<std::string> getPropertyNamesVector() const ;
        ObjectHandler::property_t getSystemProperty(const std::string &) const ;
		void setSystemProperty(const std::string & name, const ObjectHandler::property_t & value) ;

    protected :

        static const char * mPropertyNames[] ;
        static std::set<std::string> mSystemPropertyNames ;
        bool permanent_ ;
        template<class Archive>
        void serialize(Archive& ar, const unsigned int) {
        boost::serialization::void_cast_register<interestRateSwapBootstrapHelperValueObject2, ObjectHandler::ValueObject>(this, this) ;

            ar  & boost::serialization::make_nvp("ObjectId", objectId_)
                & boost::serialization::make_nvp("ClassName", className_)
                & boost::serialization::make_nvp("Permanent", permanent_)
                & boost::serialization::make_nvp("User Properties", userProperties) ;

            } ;

        } ;

    }

}

#endif