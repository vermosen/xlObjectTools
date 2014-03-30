/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 21/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/tools/interestRateConvention/interestRateConvention.hpp>

namespace QuantLib {

        interestRateConvention::interestRateConvention(const DayCounter & daycounter,
                                                       const Compounding & compounding,
                                                       const Frequency & frequency,
                                                       const BusinessDayConvention & businessDayConvention) :

            frequency_(frequency),
            daycounter_(daycounter),
            compounding_(compounding),
            businessDayConvention_(businessDayConvention) {}

    }
