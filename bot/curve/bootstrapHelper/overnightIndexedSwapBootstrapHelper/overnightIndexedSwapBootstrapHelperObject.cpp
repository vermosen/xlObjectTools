/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/overnightIndexedSwapBootstrapHelper/overnightIndexedSwapBootstrapHelperObject.hpp>


namespace QuantLibAddin {


                overnightIndexedSwapBootstrapHelperObject::overnightIndexedSwapBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject> & valueObject,
																									 const QuantLib::Date & startDate,
																									 const QuantLib::Date  & maturityDate,
																									 const QuantLib::Handle<QuantLib::Quote> & fixedRate,
																									 const boost::shared_ptr<QuantLib::OvernightIndex> & index,
																									 const bool permanent) : RateHelper(valueObject, permanent) {


                libraryObject_ = boost::shared_ptr<QuantLib::RateHelper>(new
                    QuantLib::DatedOISRateHelper(startDate,
												 maturityDate,
												 fixedRate,
												 index)) ;


            }


    }

