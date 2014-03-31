/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef btan_object_hpp
#define btan_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/btan.hpp>

#include <bot/instruments/bond/btan/btanValueObject.hpp>

namespace QuantLibAddin {

        class btanObject : public Bond {

        public :

                btanObject::btanObject(boost::shared_ptr<QuantLibAddin::ValueObjects::btanValueObject> & valueObject,
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