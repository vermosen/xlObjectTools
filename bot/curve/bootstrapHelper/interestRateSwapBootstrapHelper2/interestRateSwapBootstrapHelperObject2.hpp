/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef interest_rate_swap_boostrap_helper_object2
#define interest_rate_swap_boostrap_helper_object2

#include <qlo/ratehelpers.hpp>

#include <qle/instruments/interestRateSwap/interestRateSwap.hpp>
#include <qle/termStructure/bootstrapHelper/interestRateSwapBootstrapHelper/interestRateSwapBootstrapHelper.hpp>

#include <ql/termstructures/yield/ratehelpers.hpp>

#include <bot/swap/interestRateSwap/interestRateSwapObject.hpp>
#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper2/interestRateSwapBootstrapHelperValueObject2.hpp>

namespace QuantLibAddin {

        class interestRateSwapBootstrapHelperObject2 : public RateHelper {

            public :

			     interestRateSwapBootstrapHelperObject2(
					 boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject2> & valueObject,
					 const QuantLib::Handle<QuantLib::Quote>& rate,
					 const QuantLib::Period & tenor,
					 const QuantLib::Calendar & calendar,
					 QuantLib::Frequency fixedFrequency,
					 QuantLib::BusinessDayConvention fixedConvention,
					 const QuantLib::DayCounter & fixedDayCount,
					 const boost::shared_ptr<QuantLib::IborIndex>& iborIndex,
					 const QuantLib::Handle<QuantLib::Quote>& spread = QuantLib::Handle<QuantLib::Quote>(),
					 const QuantLib::Period  & fwdStart = 0 * QuantLib::Days,
					 const QuantLib::Handle<QuantLib::YieldTermStructure> & discountingCurve = QuantLib::Handle<QuantLib::YieldTermStructure>(),
					 const bool permanent = true) ;

            } ;

    }

#endif