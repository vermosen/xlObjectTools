/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef bu_bill_object_hpp
#define bu_bill_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/buBill.hpp>

#include <bot/instruments/bond/buBill/buBillValueObject.hpp>

namespace QuantLibAddin {

        class buBillObject : public Bond {

        public :

                buBillObject::buBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::buBillValueObject> & valueObject,
                                           const QuantLib::Date & maturityDate,
                                           const QuantLib::Date & issueDate,
                                           const bool permanent) ;

            } ;

    }

#endif