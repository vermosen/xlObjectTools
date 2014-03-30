/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef deposit_bootstrap_helper_object
#define deposit_bootstrap_helper_object

#include <qlo/ratehelpers.hpp>

#include <ql/instruments/bond.hpp>
#include <ql/termstructures/yield/bondhelpers.hpp>
#include <ql/instruments/bonds/deposit.hpp>
#include <ql/termStructures/yield/depositBootstrapHelper.hpp>

#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperValueObject.hpp>
namespace QuantLibAddin {

        class depositBootstrapHelperObject : public RateHelper {

            public :

                depositBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject> & valueObject,
                                             const boost::shared_ptr<QuantLib::deposit> & deposit,
                                             const QuantLib::Handle<QuantLib::Quote> & depositPrice,
                                             const bool permanent) ;

            } ;

    }

#endif