/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef aussie_note_object_hpp
#define aussie_note_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/australianTreasuryNote.hpp>
#include <ql/currencies/oceania.hpp>

#include <bot/instruments/bond/australianTreasuryNote/australianTreasuryNoteValueObject.hpp>

namespace QuantLibAddin {

        class australianTreasuryNoteObject : public Bond {

        public :

                australianTreasuryNoteObject::australianTreasuryNoteObject(boost::shared_ptr<QuantLibAddin::ValueObjects::australianTreasuryNoteValueObject> & valueObject,
                                         const QuantLib::Date & issueDate,
                                         const QuantLib::Date & effectiveDate,
                                         const QuantLib::Date & firstCouponDate,
                                         const QuantLib::Date & penultimateDate,
                                         const QuantLib::Date & maturityDate,
                                         const QuantLib::Rate & couponRate,
                                         const bool permanent) ;

            } ;

    }

#endif