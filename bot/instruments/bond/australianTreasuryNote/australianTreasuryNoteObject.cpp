/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/australianTreasuryNote/australianTreasuryNoteObject.hpp>

namespace QuantLibAddin {

    australianTreasuryNoteObject::australianTreasuryNoteObject(
		boost::shared_ptr<QuantLibAddin::ValueObjects::australianTreasuryNoteValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & effectiveDate,
                             const QuantLib::Date & firstCouponDate,
                             const QuantLib::Date & lastCouponDate,
                             const QuantLib::Date & maturityDate,
                             const QuantLib::Rate & couponRate,
                             const bool permanent) : Bond(valueObject, std::string(""), QuantLib::AUDCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::australianTreasuryNote> (new
                QuantLib::australianTreasuryNote(
					issueDate, 
                    effectiveDate,
                    firstCouponDate,
                    lastCouponDate,
                    maturityDate,
                    couponRate)) ;

        } ;
            
    }