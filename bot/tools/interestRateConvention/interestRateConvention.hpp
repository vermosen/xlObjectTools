/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 21/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef interest_rate_convention_hpp
#define interest_rate_convention_hpp


#include <ql/interestrate.hpp>

#include <ql/quotes/simplequote.hpp>

#include <ql/time/businessdayconvention.hpp>


namespace QuantLib {

    class interestRateConvention {

    public :


        interestRateConvention(const DayCounter & daycounter,
                               const Compounding & compounding,
                               const Frequency & frequency,
                               const BusinessDayConvention & businessDayConvention) ;


        inline InterestRate conventionalInterestRate(const QuantLib::SimpleQuote & quote) {


                return InterestRate(quote.value(),
                        daycounter_,
                        compounding_,
                        frequency_) ;

            } ;


        inline DayCounter daycounter() {return daycounter_ ;} ;

        inline Compounding compounding() {return compounding_ ;} ;

        inline Frequency frequency() {return frequency_ ;} ;

        inline BusinessDayConvention businessDayConvention() {return businessDayConvention_ ;} ;


    private :


        DayCounter daycounter_ ;

        Compounding compounding_ ;

        Frequency frequency_ ;

        BusinessDayConvention businessDayConvention_ ;


    } ;


}

#endif
