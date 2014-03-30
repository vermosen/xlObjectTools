/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/kangarooBond/kangarooBondObject.hpp>

namespace QuantLibAddin {

kangarooBondObject::kangarooBondObject(boost::shared_ptr<QuantLibAddin::ValueObjects::kangarooBondValueObject> & valueObject,
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
                                       const QuantLib::Natural & exDividendDays,
                                       const bool permanent)

            : Bond(valueObject, std::string(""), QuantLib::AUDCurrency(), permanent) {

            libraryObject_ = boost::shared_ptr<QuantLib::kangarooBond> (new
                QuantLib::kangarooBond(issueDate,
                                               maturityDate,
                                               frequency,
                                               daycounter,
                                               couponRate,
                                               effectiveDate,
                                               firstCouponDate,
                                               lastCouponDate,
                                               settleDays,
                                               endOfMonth,
                                               exDividendDays)) ;

        }

    }