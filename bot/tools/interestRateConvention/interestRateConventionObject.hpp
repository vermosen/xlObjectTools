/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 21/11/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef interest_rate_convention_object_hpp
#define interest_rate_convention_object_hpp

#include <oh/libraryobject.hpp>

#include <ql/interestrate.hpp>
#include <bot/tools/interestRateConvention/interestRateConventionValueObject.hpp>

namespace QuantLibAddin {

    class interestRateConventionObject : public ObjectHandler::LibraryObject<QuantLib::InterestRate> {

    public :

        interestRateConventionObject(
                 boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateConventionValueObject> & valueObject,
                 const QuantLib::DayCounter & daycounter,
                 const QuantLib::Compounding & compounding,
                 const QuantLib::Frequency & frequency,
                 const QuantLib::BusinessDayConvention & businessDayConvention,
                 const bool permanent) ;

        inline QuantLib::DayCounter daycounter() const {return libraryObject_->dayCounter() ;} ;
        inline QuantLib::Compounding compounding() const {return libraryObject_->compounding() ;} ;
        inline QuantLib::Frequency frequency() const {return libraryObject_->frequency() ;} ;
        inline QuantLib::BusinessDayConvention businessDayConvention() const {return libraryObject_->businessDayCounvention() ;} ;

        } ;

    }

#endif
