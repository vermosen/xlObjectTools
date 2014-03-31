/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/leg/fixedLegAustralia/fixedLegAustraliaObject.hpp>

namespace QuantLibAddin {

    fixedLegAustraliaObject::fixedLegAustraliaObject(boost::shared_ptr<QuantLibAddin::ValueObjects::fixedLegAustraliaValueObject> & valueObject,
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
                new QuantLib::Leg(QuantLib::fixedLegAustralia(effectiveDate, 
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
                                                                      endOfMonth).operator QuantLib::Leg())) ;

        } ;

    }