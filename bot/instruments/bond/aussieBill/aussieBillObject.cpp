/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/aussieBill/aussieBillObject.hpp>
#include <ql/currencies/oceania.hpp>

namespace QuantLibAddin {

    aussieBillObject::aussieBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::aussieBillValueObject> & valueObject,
                                       const QuantLib::Date & maturityDate,
                                       const QuantLib::Date & issueDate,
                                       const QuantLib::Natural & settlementDays,
                                       const bool permanent) : Bond(valueObject, std::string("australian treasury note"), QuantLib::AUDCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::aussieBill> (new
                QuantLib::aussieBill(maturityDate, 
                                     issueDate,
                                     settlementDays)) ;

        } ;
            
    }