/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/leg/floatLegUnitedStates/floatLegUnitedStatesObject.hpp>

namespace QuantLibAddin {

        floatLegUnitedStatesObject::floatLegUnitedStatesObject(
                                           boost::shared_ptr<QuantLibAddin::ValueObjects::floatLegUnitedStatesValueObject> & valueObject,
                                           const QuantLib::Date & effectiveDate,
                                           const QuantLib::Date & firstCouponDate,
                                           const QuantLib::Date & lastCouponDate,
                                           const QuantLib::Date & maturityDate,
                                           const boost::shared_ptr<QuantLib::IborIndex> & index,
                                           const QuantLib::Natural & fixingDays,
                                           const QuantLib::Frequency & legFrequency,
                                           const QuantLib::DayCounter & legDaycounter,
                                           const QuantLib::Real & notional,
                                           const QuantLib::Spread & spread,
                                           const QuantLib::BusinessDayConvention & paymentConvention,
                                           const QuantLib::BusinessDayConvention & terminationPaymentConvention,
                                           const bool & endOfMonth,
                                           const bool & permanent) : Leg(valueObject, permanent) {

                libraryObject_ = boost::shared_ptr<QuantLib::Leg>(
                    new QuantLib::Leg(QuantLib::floatLegUnitedStates(effectiveDate, 
                                                                     firstCouponDate,
                                                                     lastCouponDate,
                                                                     maturityDate,
                                                                     index,
                                                                     fixingDays,
                                                                     legFrequency,
                                                                     legDaycounter,
                                                                     notional,
                                                                     spread,
                                                                     paymentConvention,
                                                                     terminationPaymentConvention,
                                                                     endOfMonth))) ;

            } ;

        QuantLib::Real floatLegUnitedStatesObject::accruedAmount(bool includeSettlementDateFlows,
                                                       const QuantLib::Date & settlementDate) const {

                return QuantLib::CashFlows::accruedAmount(* libraryObject_,
                                                          includeSettlementDateFlows,
                                                          settlementDate) ;

            }

        QuantLib::Real floatLegUnitedStatesObject::currentFixing(bool includeSettlementDateFlows,
                                                                 const QuantLib::Date & settlementDate) const {


                return QuantLib::CashFlows::nextCouponRate(* libraryObject_,
                                                           includeSettlementDateFlows,
                                                           settlementDate) ;

            }

        void floatLegUnitedStatesObject::setFixingIndex(QuantLib::Handle<QuantLib::YieldTermStructure> index_) {
        
                    // ligature de la courbe forward
                for (std::vector<boost::shared_ptr<QuantLib::CashFlow> >::const_iterator Jt = libraryObject_->begin() ; Jt != libraryObject_->end() ; ++Jt) {

                            // IborCoupon ?
                        boost::shared_ptr<QuantLib::IborCoupon> fc = 
                            boost::dynamic_pointer_cast<QuantLib::IborCoupon>(* Jt) ;

                        //if (fc) fc->iborIndex()->forwardingTermStructure().linkTo(* index_, false) ;
        
                    }

            }

    }