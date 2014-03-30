/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/07/10
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef interest_rate_swap_object
#define interest_rate_swap_object

#include <ql/instruments/vanillaSwap2.hpp>

#include <qlo/swap.hpp>

#include <bot/leg/activeLeg.hpp>
#include <bot/swap/interestRateSwap/interestRateSwapValueObject.hpp>

namespace QuantLibAddin {

    class interestRateSwapObject : public Instrument {

            public :

                interestRateSwapObject(
                    boost::shared_ptr<ValueObjects::interestRateSwapValueObject> & valueObject,
                    boost::shared_ptr<Leg> & fixedLeg,
                    boost::shared_ptr<Leg> & floatLeg,
                    const QuantLib::vanillaSwap2::Type & payFixed,
                    const bool & permanent = true) ;

                long getLegRank(const std::string & legId_) const ;
                std::string getLegType(const QuantLib::Size & legRank_) const ;
                std::string getLegType(const std::string & legId_) const ;

            protected :

                OH_OBJ_CTOR(interestRateSwapObject, Instrument) ;

        } ;


    }

#endif