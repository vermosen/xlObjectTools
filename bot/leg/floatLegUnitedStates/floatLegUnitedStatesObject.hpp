/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef float_leg_united_states_object_hpp
#define float_leg_united_states_object_hpp

#include <qlo/leg.hpp>

#include <ql/indexes/IborIndex.hpp>
#include <ql/cashflows/cashflows.hpp>
#include <ql/utilities/null.hpp>
#include <ql/instruments/legs/floatLegUnitedStates.hpp>

#include <bot/leg/floatLegUnitedStates/floatLegUnitedStatesValueObject.hpp>

namespace QuantLibAddin {

        class floatLegUnitedStatesObject : public Leg {

            public :

                floatLegUnitedStatesObject::floatLegUnitedStatesObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::floatLegUnitedStatesValueObject> & valueObject,
                    const QuantLib::Date & effectiveDate,
                    const QuantLib::Date & firstCouponDate,
                    const QuantLib::Date & lastCouponDate,
                    const QuantLib::Date & maturityDate,
                    const boost::shared_ptr<QuantLib::IborIndex> & index,
                    const QuantLib::Natural & fixingDays = QuantLib::Null<QuantLib::Natural>(),
                    const QuantLib::Frequency & legFrequency = QuantLib::Semiannual,
                    const QuantLib::DayCounter & legDaycounter = QuantLib::Actual360(),
                    const QuantLib::Real & notional = 100.0,
                    const QuantLib::Spread & spread = 0.0,
                    const QuantLib::BusinessDayConvention & paymentConvention = QuantLib::ModifiedFollowing,
                    const QuantLib::BusinessDayConvention & terminationPaymentConvention = QuantLib::ModifiedFollowing,
                    const bool & endOfMonth = true,
                    const bool & permanent = true) ;


                QuantLib::Real accruedAmount(bool includeSettlementDateFlow,
                                             const QuantLib::Date& settlementDates) const ;

				QuantLib::Real currentFixing(bool includeSettlementDateFlow,
                                             const QuantLib::Date & settlementDates) const ;

                void setFixingIndex(QuantLib::Handle<QuantLib::YieldTermStructure> index_) ;



        } ;

    }

#endif