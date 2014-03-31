/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/deposit/depositObject.hpp>

namespace QuantLibAddin {

depositObject::depositObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositValueObject> & valueObject,
                             const QuantLib::Date & startDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Calendar & calendar,
                             const QuantLib::Natural & settlementDays,
                             const QuantLib::BusinessDayConvention & paymentConvention,
                             const bool & endOfMonth,
                             const bool permanent) : Bond(valueObject, std::string("currency deposit"), QuantLib::Currency(), permanent) {// undefined CCY
        
            libraryObject_ = boost::shared_ptr<QuantLib::deposit> (new
                QuantLib::deposit(startDate,
										  maturityDate,
										  calendar,
										  settlementDays,
										  paymentConvention)) ;

        } ;
            
    }