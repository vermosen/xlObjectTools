/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/btan/btanObject.hpp>
#include <ql/currencies/europe.hpp>

namespace QuantLibAddin {

    btanObject::btanObject(boost::shared_ptr<QuantLibAddin::ValueObjects::btanValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & effectiveDate,
                             const QuantLib::Date & firstCouponDate,
                             const QuantLib::Date & lastCouponDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Rate & couponRate,
                             const bool permanent) : Bond(valueObject, std::string("french medium term note"), QuantLib::EURCurrency(), true) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::btan> (new
                QuantLib::btan(issueDate, 
                                       effectiveDate,
                                       firstCouponDate,
                                       lastCouponDate,
                                       maturityDate,
                                       couponRate)) ;

        } ;
            
    }