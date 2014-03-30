/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/serialization/serializationfactory.hpp>

#include <bot/serialization/create/create_all.hpp>

namespace QuantLibAddin {

    void serializationFactory::registerCreators() {

            // leg
        registerCreator("fixedLegAustraliaValueObject", create_fixedLegAustralia) ;

        registerCreator("interestRateSwapValueObject", create_interestRateSwap) ;


    }

}