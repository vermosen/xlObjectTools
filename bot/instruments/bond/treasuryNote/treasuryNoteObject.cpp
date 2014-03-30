/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/treasuryNote/treasuryNoteObject.hpp>

namespace QuantLibAddin {

    treasuryNoteObject::treasuryNoteObject(boost::shared_ptr<QuantLibAddin::ValueObjects::treasuryNoteValueObject> & valueObject,
                                           const QuantLib::Date & issueDate,
                                           const QuantLib::Date & effectiveDate,
                                           const QuantLib::Date & firstCouponDate,
                                           const QuantLib::Date & lastCouponDate,
                                           const QuantLib::Date & maturityDate,
                                           const QuantLib::Rate & couponRate,
                                           const bool permanent) : Bond(valueObject, std::string(""), QuantLib::USDCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::treasuryNote> (new
                QuantLib::treasuryNote(issueDate, 
                                       effectiveDate,
                                       firstCouponDate,
                                       lastCouponDate,
                                       maturityDate,
                                       couponRate)) ;

        } ;
            
    }