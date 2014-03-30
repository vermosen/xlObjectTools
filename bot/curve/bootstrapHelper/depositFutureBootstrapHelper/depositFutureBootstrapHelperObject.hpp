/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef deposit_future_bootstrap_helper_object
#define deposit_future_bootstrap_helper_object


#include <qlo/ratehelpers.hpp>

#include <ql/indexes/iborindex.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
#include <ql/time/imm.hpp>

#include <bot/curve/bootstrapHelper/depositFutureBootstrapHelper/depositFutureBootstrapHelperValueObject.hpp>

#include <ql/quotes/futuresConvexityAdjustmentQuote2.hpp>

namespace QuantLibAddin {

        class depositFutureBootstrapHelperObject : public RateHelper {

            public :

                depositFutureBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositFutureBootstrapHelperValueObject> & valueObject,
                                                   const std::string & immCode,
                                                   const QuantLib::Date & effectiveDate,
                                                   const QuantLib::Handle<QuantLib::Quote> & depositFuturePrice,
                                                   const boost::shared_ptr<QuantLib::IborIndex> & iborIndex,
                                                   const QuantLib::Handle<QuantLib::Quote> & convexityAdjustement = QuantLib::Handle<QuantLib::Quote>(),
                                                   const QuantLib::Handle<QuantLib::Quote> & meanReverting = QuantLib::Handle<QuantLib::Quote>(),
                                                   const bool permanent = true) ;

            } ;

    }

#endif