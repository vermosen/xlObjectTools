/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef aussie_bill_object_hpp
#define aussie_bill_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/aussieBill.hpp>
#include <ql/currencies/oceania.hpp>

#include <bot/instruments/bond/aussieBill/aussieBillValueObject.hpp>

namespace QuantLibAddin {

        class aussieBillObject : public Bond {

        public :

                aussieBillObject::aussieBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::aussieBillValueObject> & valueObject,
                                         const QuantLib::Date & maturityDate,
                                         const QuantLib::Date & issueDate,
                                         const QuantLib::Natural & settlementDays,
                                         const bool permanent) ;

            } ;

    }

#endif