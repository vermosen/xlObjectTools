/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef kangaroo_bond_object_hpp
#define kangaroo_bond_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/kangarooBond.hpp>
#include <ql/currencies/oceania.hpp>

#include <bot/instruments/bond/kangarooBond/kangarooBondValueObject.hpp>

namespace QuantLibAddin {

        class kangarooBondObject : public Bond {

            public :

                kangarooBondObject(boost::shared_ptr<QuantLibAddin::ValueObjects::kangarooBondValueObject> & valueObject,
                                  const QuantLib::Date & issueDate,
                                  const QuantLib::Date & maturityDate,
                                  const QuantLib::Frequency & frequency,
                                  const QuantLib::DayCounter & daycounter,
                                  const QuantLib::Rate & couponRate,
                                  const QuantLib::Date & effectiveDate = QuantLib::Date(),
                                  const QuantLib::Date & firstCouponDate = QuantLib::Date(),
                                  const QuantLib::Date & penultimateDate = QuantLib::Date(),
                                  const QuantLib::Natural & settleDays = 3,
                                  const bool & endOfMonth = true,
                                  const QuantLib::Natural & exDividendDays = 7,
                                  const bool permanent = true) ;


            } ;


    }

#endif