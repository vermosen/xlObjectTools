/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/07/10
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef zero_coupon_inflation_swap_united_states_object
#define zero_coupon_inflation_swap_united_states_object

#include <qle/instruments/zeroCouponInflationSwapUnitedStates/zeroCouponInflationSwapUnitedStates.hpp>

#include <qle/index/inflationIndex/inflationIndex.hpp>

#include <qlo/swap.hpp>

#include <bot/swap/zeroCouponInflationSwapUnitedStates/zeroCouponInflationSwapUnitedStatesValueObject.hpp>


namespace QuantLibAddin {

    class zeroCouponInflationSwapUnitedStatesObject : public Swap {


            public :


                zeroCouponInflationSwapUnitedStatesObject(
                    boost::shared_ptr<ValueObjects::zeroCouponInflationSwapUnitedStatesValueObject> & valueObject,
                    boost::shared_ptr<Leg> & leg1,
                    boost::shared_ptr<Leg> & leg2,
                    const bool & payFixed = true,
                    const bool & permanent = true) ;

                long getLegRank(const std::string & legId_) const ;

                std::string getLegType(const QuantLib::Size & legRank_) const ;

                std::string getLegType(const std::string & legId_) const ;


            protected :


                OH_OBJ_CTOR(zeroCouponInflationSwapUnitedStatesObject, Swap) ;


        } ;


    }

#endif

