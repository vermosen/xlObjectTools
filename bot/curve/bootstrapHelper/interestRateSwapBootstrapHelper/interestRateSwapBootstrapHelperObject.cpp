/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper/interestRateSwapBootstrapHelperObject.hpp>


namespace QuantLibAddin {

        interestRateSwapBootstrapHelperObject::interestRateSwapBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject> & valueObject,
                                                                                     const QuantLib::Handle<QuantLib::Quote> & swapRate,
                                                                                     const boost::shared_ptr<QuantLibExtended::interestRateSwap> & swap,
                                                                                     const QuantLib::Handle<QuantLib::YieldTermStructure> & discount,
                                                                                     const bool permanent) : RateHelper(valueObject, permanent) {
            

                libraryObject_ = boost::shared_ptr<QuantLib::RateHelper>(new
                    QuantLibExtended::interestRateSwapBootstrapHelper(swapRate,
                                                                      swap,
                                                                      discount)) ;


            }


    }