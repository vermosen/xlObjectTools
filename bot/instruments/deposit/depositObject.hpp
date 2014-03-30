/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef deposit_object
#define deposit_object

#include <qlo/bonds.hpp>

#include <ql/instruments/bond.hpp>

#include <ql/time/daycounters/actual360.hpp>

#include <qle/instruments/deposit/deposit.hpp>

#include <bot/instruments/deposit/depositValueObject.hpp>

namespace QuantLibAddin {

    class depositObject : public Bond {

    public :

        depositObject::depositObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositValueObject> & valueObject,
                                     const QuantLib::Date & startDate,
                                     const QuantLib::Date & maturityDate,
                                     const QuantLib::Calendar & calendar,
                                     const QuantLib::Natural & settlementDays = 2,
                                     const QuantLib::BusinessDayConvention & paymentConvention = QuantLib::ModifiedFollowing,
                                     const bool & endOfMonth  = false,
                                     const bool permanent = true) ;

        } ;

    }

#endif