/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef oat_object_hpp
#define oat_object_hpp

#include <qlo/bonds.hpp>

#include <ql/instruments/bonds/oat.hpp>

#include <bot/instruments/bond/oat/oatValueObject.hpp>

namespace QuantLibAddin {

        class oatObject : public Bond {

        public :

                oatObject::oatObject(boost::shared_ptr<QuantLibAddin::ValueObjects::oatValueObject> & valueObject,
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