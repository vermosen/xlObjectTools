/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef bu_note_object_hpp
#define bu_note_object_hpp

#include <qlo/bonds.hpp>

#include <qle/instruments/buNote/buNote.hpp>

#include <bot/instruments/bond/buNote/buNoteValueObject.hpp>

namespace QuantLibAddin {

        class buNoteObject : public Bond {

        public :

                buNoteObject::buNoteObject(boost::shared_ptr<QuantLibAddin::ValueObjects::buNoteValueObject> & valueObject,
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