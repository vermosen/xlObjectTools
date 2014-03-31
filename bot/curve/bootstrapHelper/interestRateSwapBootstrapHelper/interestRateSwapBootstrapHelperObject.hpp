/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef interest_rate_swap_boostrap_helper_object
#define interest_rate_swap_boostrap_helper_object

#include <qlo/ratehelpers.hpp>

#include <ql/instruments/vanillaSwap2.hpp>
#include <ql/termStructures/yield/interestRateSwapBootstrapHelper.hpp>

#include <bot/swap/interestRateSwap/interestRateSwapObject.hpp>
#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper/interestRateSwapBootstrapHelperValueObject.hpp>

namespace QuantLibAddin {

        class interestRateSwapBootstrapHelperObject : public RateHelper {

            public :

                interestRateSwapBootstrapHelperObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject> & valueObject,
                    const QuantLib::Handle<QuantLib::Quote> & swapRate,
                    const boost::shared_ptr<QuantLib::vanillaSwap2> & swap,
                    const QuantLib::Handle<QuantLib::YieldTermStructure> & discount = QuantLib::Handle<QuantLib::YieldTermStructure>(),
                    const bool permanent = true) ;

            } ;

    }

#endif