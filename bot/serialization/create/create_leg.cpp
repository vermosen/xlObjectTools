/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/serialization/create/create_leg.hpp>

namespace QuantLibAddin {

    boost::shared_ptr<ObjectHandler::Object> create_fixedLegAustralia(
        const boost::shared_ptr<ObjectHandler::ValueObject> & valueObject) {

            //convert input datatypes to C++ datatypes
        QuantLib::DayCounter legDaycounter =
            ObjectHandler::daycountFactory()(ObjectHandler::convert2<std::string>(valueObject->getProperty("DayCounter"))) ;

        QuantLib::Compounding legCompounding =
            ObjectHandler::convert2<QuantLib::Compounding>(valueObject->getProperty("Compounding")) ;

        QuantLib::Frequency legFrequency =
            ObjectHandler::convert2<QuantLib::Frequency>(valueObject->getProperty("Frequency")) ;

        QuantLib::Date effectiveDate(
            ObjectHandler::convert2<QuantLib::BigInteger>(valueObject->getProperty("effectiveDate"))) ;

        QuantLib::Date firstCouponDate(
            ObjectHandler::convert2<QuantLib::BigInteger>(valueObject->getProperty("firstCouponDate"))) ;

        QuantLib::Date lastCouponDate(
            ObjectHandler::convert2<QuantLib::BigInteger>(valueObject->getProperty("lastCouponDate"))) ;

        QuantLib::Date maturityDate(
            ObjectHandler::convert2<QuantLib::BigInteger>(valueObject->getProperty("maturityDate"))) ;

        QuantLib::BusinessDayConvention paymentConvention =
            ObjectHandler::convert2<QuantLib::BusinessDayConvention >(valueObject->getProperty("paymentConvention")) ;

        QuantLib::BusinessDayConvention terminationPaymentConvention =
            ObjectHandler::convert2<QuantLib::BusinessDayConvention>(valueObject->getProperty("terminationPaymentConvention")) ;

        bool permanent =
            ObjectHandler::convert2<bool>(valueObject->getProperty("permanent")) ;
        
        bool endOfMonth =
            ObjectHandler::convert2<bool>(valueObject->getProperty("endOfMonth")) ;

        double fixedCouponRate =
            ObjectHandler::convert2<double>(valueObject->getProperty("fixedCouponRate")) ;

        double notional =
            ObjectHandler::convert2<double>(valueObject->getProperty("notional")) ;

        boost::shared_ptr<ObjectHandler::Object> object(
            new QuantLibAddin::fixedLegAustraliaObject(
                boost::dynamic_pointer_cast<QuantLibAddin::ValueObjects::fixedLegAustraliaValueObject>(valueObject),
                    effectiveDate,
                    firstCouponDate,
                    lastCouponDate,
                    maturityDate,
                    fixedCouponRate,
                    legFrequency,
                    legDaycounter,
                    legCompounding,
                    notional,
                    paymentConvention,
                    terminationPaymentConvention,
                    endOfMonth,
                    permanent)) ;

        return object ;


    }

}
