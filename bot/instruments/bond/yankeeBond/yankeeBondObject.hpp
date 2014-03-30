/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef yankee_bond_object_hpp
#define yankee_bond_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/yankeeBond.hpp>

#include <bot/instruments/bond/yankeeBond/yankeeBondValueObject.hpp>

namespace QuantLibAddin {

    class yankeeBondObject : public Bond {

    public :

        yankeeBondObject(boost::shared_ptr<QuantLibAddin::ValueObjects::yankeeBondValueObject> & valueObject,
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
                         const bool permanent = true) ;

        } ;

    }

#endif
