/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/bondBootstrapHelper/bondBootstrapHelperObject.hpp>

namespace QuantLibAddin {

    bondBootstrapHelperObject::bondBootstrapHelperObject(
		boost::shared_ptr<QuantLibAddin::ValueObjects::bondBootstrapHelperValueObject> & valueObject,
        const boost::shared_ptr<QuantLib::Bond> & bond,
        const QuantLib::Handle<QuantLib::Quote> & bondPrice,
        const bool permanent) : RateHelper(valueObject, permanent) {
            
                libraryObject_ = boost::shared_ptr<QuantLib::RateHelper>(new
                    QuantLib::BondHelper(bondPrice,
                                         bond)) ;

            }

    }