/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/serialization/create/create_swap.hpp>

namespace QuantLibAddin {

    boost::shared_ptr<ObjectHandler::Object> create_interestRateSwap(
        const boost::shared_ptr<ObjectHandler::ValueObject> & valueObject) {

            // convert to cpp types
        bool permanent =
            ObjectHandler::convert2<bool>(valueObject->getProperty("permanent")) ;
        
        std::vector<bool> payer =
            ObjectHandler::vector::convert2<bool>(valueObject->getProperty("payer"), "payer") ;

        std::vector<boost::shared_ptr<QuantLibAddin::Leg> > legs ;

        std::vector<std::string> legNames = 
            ObjectHandler::vector::convert2<std::string>(valueObject->getProperty("LegIds"), "LegIds") ;

            // on récupère les jambes
        OH_GET_OBJECT(leg1, legNames[0], QuantLibAddin::Leg)

            legs.push_back(leg1) ;

        OH_GET_OBJECT(leg2, legNames[1], QuantLibAddin::Leg)

            legs.push_back(leg2) ;


        boost::shared_ptr<ObjectHandler::Object> object(
            new QuantLibAddin::interestRateSwapObject(
                boost::dynamic_pointer_cast<QuantLibAddin::ValueObjects::interestRateSwapValueObject>(valueObject),
                    legs[0],
                    legs[1],
                    (payer[0] == true ? 
                    QuantLibExtended::interestRateSwap::Receiver : 
                    QuantLibExtended::interestRateSwap::Payer),
                    permanent)) ;


        return object ;


    }

}
