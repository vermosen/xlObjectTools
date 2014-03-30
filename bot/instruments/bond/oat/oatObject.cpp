/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/oat/oatObject.hpp>

namespace QuantLibAddin {

    oatObject::oatObject(boost::shared_ptr<QuantLibAddin::ValueObjects::oatValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & effectiveDate,
                             const QuantLib::Date & firstCouponDate,
                             const QuantLib::Date & lastCouponDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Rate & couponRate,
                             const bool permanent) : Bond(valueObject, permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLibExtended::oat> (new
                QuantLibExtended::oat(issueDate, 
                                             effectiveDate,
                                             firstCouponDate,
                                             lastCouponDate,
                                             maturityDate,
                                             couponRate)) ;

        } ;
            
    }