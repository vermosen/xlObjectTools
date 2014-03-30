/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef fixed_leg_australia_object_hpp
#define fixed_leg_australia_object_hpp

#include <qlo/Leg.hpp>

#include <ql/instruments/legs/fixedLegAustralia.hpp>

#include <bot/leg/fixedLegAustralia/fixedLegAustraliaValueObject.hpp>

namespace QuantLibAddin {

        class fixedLegAustraliaObject : public Leg  {

            public :

                fixedLegAustraliaObject::fixedLegAustraliaObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::fixedLegAustraliaValueObject> & valueObject,
                    const QuantLib::Date & effectiveDate,
                    const QuantLib::Date & firstCouponDate,
                    const QuantLib::Date & lastCouponDate,
                    const QuantLib::Date & maturityDate,
                    const QuantLib::Rate & fixedCouponRate,
                    const QuantLib::Frequency & legFrequency = QuantLib::Semiannual,
                    const QuantLib::DayCounter & legDaycounter = QuantLib::Actual365Fixed(),
                    const QuantLib::Compounding & legCompounding = QuantLib::Compounded,
                    const QuantLib::Real & notional = 100.0,
                    const QuantLib::BusinessDayConvention & paymentConvention = QuantLib::ModifiedFollowing,
                    const QuantLib::BusinessDayConvention & terminationPaymentConvention = QuantLib::ModifiedFollowing,
                    const bool & endOfMonth = true,
                    const bool & permanent = true) ;

        } ;

    }

#endif