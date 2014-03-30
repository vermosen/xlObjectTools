/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef tbill_object_hpp
#define tbill_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/treasuryBill.hpp>
#include <ql/currencies/america.hpp>

#include <bot/instruments/bond/treasuryBill/treasuryBillValueObject.hpp>

namespace QuantLibAddin {

    class treasuryBillObject : public Bond {

    public :

        treasuryBillObject::treasuryBillObject(boost::shared_ptr<QuantLibAddin::ValueObjects::treasuryBillValueObject> & valueObject,
                                 const QuantLib::Date & issueDate,
                                 const QuantLib::Date & maturityDate,
                                 const bool permanent) ;

        } ;

    }

#endif