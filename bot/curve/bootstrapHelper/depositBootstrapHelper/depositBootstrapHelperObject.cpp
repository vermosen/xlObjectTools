/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/bootstrapHelper/depositBootstrapHelper/depositBootstrapHelperObject.hpp>


namespace QuantLibAddin {

    depositBootstrapHelperObject::depositBootstrapHelperObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject> & valueObject,
                                                               const boost::shared_ptr<QuantLib::deposit> & deposit,
                                                               const QuantLib::Handle<QuantLib::Quote> & depositPrice,
                                                               const bool permanent) : RateHelper(valueObject, permanent) {
            
                libraryObject_ = boost::shared_ptr<QuantLib::RateHelper>(new
                    QuantLib::depositBootstrapHelper(depositPrice,
                                                     deposit)) ;

            }

    }