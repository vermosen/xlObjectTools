/*
 *  BdFObjectTool
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef zero_inflation_leg_united_states_object_hpp
#define zero_inflation_leg_united_states_object_hpp

#include <qlo/Leg.hpp>

#include <bot/leg/zeroInflationLegUnitedStates/zeroInflationLegUnitedStatesValueObject.hpp>

#include <qle/leg/zeroInflationLegUnitedStates/zeroInflationLegUnitedStates.hpp>

namespace QuantLibAddin {

        class zeroInflationLegUnitedStatesObject : public Leg  {

            public :

                zeroInflationLegUnitedStatesObject::zeroInflationLegUnitedStatesObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::zeroInflationLegUnitedStatesValueObject> & valueObject,
                    const QuantLib::Date & effectiveDate,
                    const QuantLib::Date & maturityDate,
                    const boost::shared_ptr<QuantLibExtended::inflationIndex> & index,
                    const QuantLib::Natural & fixingDays = QuantLib::Null<QuantLib::Natural>(),
                    const QuantLib::Real & notional = 100.0,
                    const bool & permanent = true) ;


        } ;

    }

#endif