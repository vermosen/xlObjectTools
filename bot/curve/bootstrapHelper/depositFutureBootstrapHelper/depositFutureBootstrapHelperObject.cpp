/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/depositFutureBootstrapHelper/depositFutureBootstrapHelperObject.hpp>


namespace QuantLibAddin {


    depositFutureBootstrapHelperObject::depositFutureBootstrapHelperObject(
		boost::shared_ptr<QuantLibAddin::ValueObjects::depositFutureBootstrapHelperValueObject> & valueObject,
        const std::string & immCode,
        const QuantLib::Date & effectiveDate,
        const QuantLib::Handle<QuantLib::Quote> & depositFuturePrice,
        const boost::shared_ptr<QuantLib::IborIndex> & iborIndex,
        const QuantLib::Handle<QuantLib::Quote> & convexityAdjustement,
        const QuantLib::Handle<QuantLib::Quote> & meanReverting,
        const bool permanent) : RateHelper(valueObject, permanent) {
    

                QuantLib::Date futureDate = QuantLib::IMM::date(immCode,
                                                                effectiveDate) ;

                boost::shared_ptr<QuantLib::Quote> futureConvxQuote(
                       new QuantLib::futuresConvexityAdjustmentQuote2(iborIndex,
                                                                      futureDate,
                                                                      depositFuturePrice,
                                                                      convexityAdjustement,
                                                                      meanReverting,
                                                                      effectiveDate)) ;

                QuantLib::Handle<QuantLib::Quote> myHandle(futureConvxQuote) ;

                libraryObject_ = boost::shared_ptr<QuantLib::FuturesRateHelper>(new
                    QuantLib::FuturesRateHelper(depositFuturePrice,
                                                futureDate,
                                                iborIndex,
                                                myHandle)) ;

    
            }


    }

