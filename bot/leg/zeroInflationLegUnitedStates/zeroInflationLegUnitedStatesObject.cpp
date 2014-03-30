/*
 *  BdFObjectTool
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/leg/zeroInflationLegUnitedStates/zeroInflationLegUnitedStatesObject.hpp>

namespace QuantLibAddin {

        zeroInflationLegUnitedStatesObject::zeroInflationLegUnitedStatesObject(
			boost::shared_ptr<QuantLibAddin::ValueObjects::zeroInflationLegUnitedStatesValueObject> & valueObject,
            const QuantLib::Date & effectiveDate,
            const QuantLib::Date & maturityDate,
            const boost::shared_ptr<QuantLibExtended::inflationIndex> & index,
            const QuantLib::Natural & fixingDays,
            const QuantLib::Real & notional,
            const bool & permanent) : Leg(valueObject, permanent) {

                libraryObject_ = boost::shared_ptr<QuantLib::Leg>(
                    new QuantLib::Leg(QuantLibExtended::zeroInflationLegUnitedStates(effectiveDate, 
                                                                                     maturityDate,
													                                 index,
													                                 fixingDays,
                                                                                     notional))) ;

            } ;


    }