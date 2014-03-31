/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/bond/btf/btfObject.hpp>
#include <ql/currencies/europe.hpp>

namespace QuantLibAddin {

    btfObject::btfObject(boost::shared_ptr<QuantLibAddin::ValueObjects::btfValueObject> & valueObject,
                                       const QuantLib::Date & maturityDate,
                                       const QuantLib::Date & issueDate,
									   const bool permanent) : Bond(valueObject, std::string("french treasury bill"), QuantLib::EURCurrency(), permanent) {
        
            libraryObject_ = boost::shared_ptr<QuantLib::btf> (new
                QuantLib::btf(maturityDate, 
                                         issueDate)) ;

        } ;
            
    }