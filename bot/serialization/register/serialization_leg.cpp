/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <oh/ohdefines.hpp>

#include <bot/serialization/register/serialization_leg.hpp>

#include <bot/leg/fixedLegAustralia/fixedLegAustraliaValueObject.hpp>

#include <bot/leg/floatLegAustralia/floatLegAustraliaValueObject.hpp>

#include <boost/serialization/shared_ptr.hpp>

#include <boost/serialization/variant.hpp>

#include <boost/serialization/vector.hpp>

namespace QuantLibAddin {


        void register_leg(boost::archive::xml_oarchive &ar) {
        

                ar.register_type<QuantLibAddin::ValueObjects::fixedLegAustraliaValueObject>() ;

                ar.register_type<QuantLibAddin::ValueObjects::floatLegAustraliaValueObject>() ;
            

            }
        
        void register_leg(boost::archive::xml_iarchive &ar) {
        

                ar.register_type<QuantLibAddin::ValueObjects::fixedLegAustraliaValueObject>() ;

                ar.register_type<QuantLibAddin::ValueObjects::floatLegAustraliaValueObject>() ;


            }
        

    }

