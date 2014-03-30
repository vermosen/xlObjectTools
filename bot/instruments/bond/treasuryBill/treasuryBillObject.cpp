/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/treasuryBill/treasuryBillObject.hpp>

namespace QuantLibAddin {

    treasuryBillObject::treasuryBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::treasuryBillValueObject> & valueObject,
                             const QuantLib::Date & issueDate,
                             const QuantLib::Date & maturityDate,
                             const bool permanent) : Bond(valueObject, std::string(""), QuantLib::USDCurrency(), permanent) {
        
                                 libraryObject_ = boost::shared_ptr<QuantLib::treasuryBill> (
									 new  QuantLib::treasuryBill(maturityDate, issueDate)) ;

        } ;
            
    }