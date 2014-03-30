/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef overnight_indexed_swap_bootstrap_object
#define overnight_indexed_swap_bootstrap_object


#include <qlo/ratehelpers.hpp>


#include <ql/termstructures/yield/oisratehelper.hpp>


#include <bot/curve/bootstrapHelper/overnightIndexedSwapBootstrapHelper/overnightIndexedSwapBootstrapHelperValueObject.hpp>


namespace QuantLibAddin {

        class overnightIndexedSwapBootstrapHelperObject : public RateHelper {

            public :

                overnightIndexedSwapBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject> & valueObject,
                                                          const QuantLib::Date & startDate,
                                                          const QuantLib::Date  & maturityDate,
                                                          const QuantLib::Handle<QuantLib::Quote> & fixedRate,
                                                          const boost::shared_ptr<QuantLib::OvernightIndex> & index,
                                                          const bool permanent = true) ;


            } ;

    }

#endif