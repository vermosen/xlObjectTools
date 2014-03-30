/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/interestRateSwapBootstrapHelper2/interestRateSwapBootstrapHelperObject2.hpp>


namespace QuantLibAddin {

        interestRateSwapBootstrapHelperObject2::interestRateSwapBootstrapHelperObject2(boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject2> & valueObject,
                                                                                       const QuantLib::Handle<QuantLib::Quote>& rate,
																					   const QuantLib::Period & tenor,
																					   const QuantLib::Calendar & calendar,
																					   QuantLib::Frequency fixedFrequency,
																					   QuantLib::BusinessDayConvention fixedConvention,
																					   const QuantLib::DayCounter & fixedDayCount,
																					   const boost::shared_ptr<QuantLib::IborIndex> & iborIndex,
																					   const QuantLib::Handle<QuantLib::Quote> & spread,
																					   const QuantLib::Period  & fwdStart,
																					   const QuantLib::Handle<QuantLib::YieldTermStructure> & discountingCurve,
                                                                                       const bool permanent) : RateHelper(valueObject, permanent) {
            


                libraryObject_ = boost::shared_ptr<QuantLib::RateHelper>(new
                    QuantLib::SwapRateHelper(rate,
										     tenor,
											 calendar,
											 fixedFrequency,
											 fixedConvention,
											 fixedDayCount,
											 iborIndex,
											 spread,
											 fwdStart,
											 discountingCurve)) ;


            }


    }