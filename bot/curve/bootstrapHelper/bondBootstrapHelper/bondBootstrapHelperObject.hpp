/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_bond_bootstrap_helper_object
#define bot_bond_bootstrap_helper_object

#include <qlo/ratehelpers.hpp>

#include <ql/instruments/bond.hpp>
#include <ql/termstructures/yield/bondhelpers.hpp>

#include <bot/curve/bootstrapHelper/bondBootstrapHelper/bondBootstrapHelperValueObject.hpp>

namespace QuantLibAddin {

        class bondBootstrapHelperObject : public RateHelper {

            public :

                bondBootstrapHelperObject(
					boost::shared_ptr<QuantLibAddin::ValueObjects::bondBootstrapHelperValueObject> & valueObject,
                    const boost::shared_ptr<QuantLib::Bond> & bond,
                    const QuantLib::Handle<QuantLib::Quote> & bondPrice,
                    const bool permanent) ;

            } ;

    }

#endif