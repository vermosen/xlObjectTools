/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/yankeeBond/yankeeBondObject.hpp>
#include <ql/currencies/america.hpp>

namespace QuantLibAddin {

yankeeBondObject::yankeeBondObject(boost::shared_ptr<QuantLibAddin::ValueObjects::yankeeBondValueObject> & valueObject,
                                   const QuantLib::Date & issueDate,
                                   const QuantLib::Date & maturityDate,
                                   const QuantLib::Frequency & frequency,
                                   const QuantLib::DayCounter & daycounter,
                                   const QuantLib::Rate & couponRate,
                                   const QuantLib::Date & effectiveDate,
                                   const QuantLib::Date & firstCouponDate,
                                   const QuantLib::Date & lastCouponDate,
                                   const QuantLib::Natural & settleDays,
                                   const bool & endOfMonth,
                                   const bool permanent) : Bond(valueObject, std::string("corporate bonds in dollar"), QuantLib::USDCurrency(), permanent) {

            libraryObject_ = boost::shared_ptr<QuantLib::yankeeBond> (new
                QuantLib::yankeeBond(issueDate,
                                             maturityDate,
                                             frequency,
                                             daycounter,
                                             couponRate,
                                             effectiveDate,
                                             firstCouponDate,
                                             lastCouponDate,
                                             settleDays,
                                             endOfMonth)) ;

        }

    }
