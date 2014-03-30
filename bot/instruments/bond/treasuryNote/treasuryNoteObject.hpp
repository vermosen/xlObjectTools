/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef tnote_object_hpp
#define tnote_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/treasuryNote.hpp>
#include <ql/currencies/america.hpp>
#include <bot/instruments/bond/treasuryNote/treasuryNoteValueObject.hpp>

namespace QuantLibAddin {

        class treasuryNoteObject : public Bond {

        public :

                treasuryNoteObject::treasuryNoteObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::treasuryNoteValueObject> & valueObject,
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