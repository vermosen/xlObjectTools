/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/oat/oatObject.hpp>
#include <ql/currencies/europe.hpp>

namespace QuantLibAddin {

    oatObject::oatObject(boost::shared_ptr<QuantLibAddin::ValueObjects::oatValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & effectiveDate,
                             const QuantLib::Date & firstCouponDate,
                             const QuantLib::Date & lastCouponDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Rate & couponRate,
                             const bool permanent) : Bond(valueObject, std::string("french treasury bond"), QuantLib::EURCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::oat> (new
                QuantLib::oat(issueDate, 
							  effectiveDate,
                              firstCouponDate,
                              lastCouponDate,
                              maturityDate,
                              couponRate)) ;

        } ;
            
    }