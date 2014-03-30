/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 21/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

namespace QuantLibAddin {

    interestRateConventionObject::interestRateConventionObject(
        boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateConventionValueObject> & valueObject,
        const QuantLib::DayCounter & daycounter,
        const QuantLib::Compounding & compounding,
        const QuantLib::Frequency & frequency,
        const QuantLib::BusinessDayConvention & businessDayConvention,
        const bool permanent) : ObjectHandler::LibraryObject<QuantLib::InterestRate>(valueObject, permanent) {

            libraryObject_ = boost::shared_ptr<QuantLib::InterestRate> (new
                QuantLib::InterestRate(0.0, daycounter,
                                       compounding,
                                       frequency,
                                       businessDayConvention)) ;

        }

    }
