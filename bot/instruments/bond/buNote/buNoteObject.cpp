/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/buNote/buNoteObject.hpp>

namespace QuantLibAddin {

    buNoteObject::buNoteObject(boost::shared_ptr<QuantLibAddin::ValueObjects::buNoteValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & effectiveDate,
                             const QuantLib::Date & firstCouponDate,
                             const QuantLib::Date & lastCouponDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Rate & couponRate,
                             const bool permanent) : Bond(valueObject, permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLibExtended::buNote> (new
                QuantLibExtended::buNote(issueDate, 
                                             effectiveDate,
                                             firstCouponDate,
                                             lastCouponDate,
                                             maturityDate,
                                             couponRate)) ;

        } ;
            
    }