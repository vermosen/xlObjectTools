/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef btf_object_hpp
#define btf_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/btf.hpp>

#include <bot/instruments/bond/btf/btfValueObject.hpp>

namespace QuantLibAddin {

        class btfObject : public Bond {

        public :

                btfObject::btfObject(boost::shared_ptr<QuantLibAddin::ValueObjects::btfValueObject> & valueObject,
                                           const QuantLib::Date & maturityDate,
                                           const QuantLib::Date & issueDate,
                                           const bool permanent) ;

            } ;

    }

#endif