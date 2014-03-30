/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/leg/fixedLegUnitedStates/fixedLegUnitedStatesObject.hpp>

namespace QuantLibAddin {

    fixedLegUnitedStatesObject::fixedLegUnitedStatesObject(boost::shared_ptr<QuantLibAddin::ValueObjects::fixedLegUnitedStatesValueObject> & valueObject,
                                                           const QuantLib::Date & effectiveDate,
                                                           const QuantLib::Date & firstCouponDate,
                                                           const QuantLib::Date & lastCouponDate,
                                                           const QuantLib::Date & maturityDate,
                                                           const QuantLib::Rate & fixedCouponRate,
                                                           const QuantLib::Frequency & legFrequency,
                                                           const QuantLib::DayCounter & legDaycounter,
                                                           const QuantLib::Compounding & legCompounding,
                                                           const QuantLib::Real & notional,
                                                           const QuantLib::BusinessDayConvention & paymentConvention,
                                                           const QuantLib::BusinessDayConvention & terminationPaymentConvention,
                                                           const bool & endOfMonth,
                                                           const bool & permanent) : Leg(valueObject, permanent) {

            libraryObject_ = boost::shared_ptr<QuantLib::Leg>(
                new QuantLib::Leg(QuantLibExtended::fixedLegUnitedStates(effectiveDate, 
                                                                         firstCouponDate,
                                                                         lastCouponDate,
                                                                         maturityDate,
                                                                         fixedCouponRate,
                                                                         legFrequency,
                                                                         legDaycounter,
                                                                         legCompounding,
                                                                         notional,
                                                                         paymentConvention,
                                                                         terminationPaymentConvention,
                                                                         endOfMonth))) ;

        } ;

    }