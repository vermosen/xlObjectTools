/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/buBill/buBillObject.hpp>
#include <ql/currencies/europe.hpp>

namespace QuantLibAddin {

    buBillObject::buBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::buBillValueObject> & valueObject,
                                       const QuantLib::Date & maturityDate,
                                       const QuantLib::Date & issueDate,
									   const bool permanent) : Bond(valueObject, std::string("german treasury bill"), QuantLib::EURCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::buBill> (new
                QuantLib::buBill(maturityDate, 
                                 issueDate)) ;

        } ;
            
    }