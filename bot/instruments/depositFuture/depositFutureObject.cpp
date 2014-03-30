/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/instruments/depositFuture/depositFutureObject.hpp>

namespace QuantLibAddin {

depositFutureObject::depositFutureObject(boost::shared_ptr<QuantLibAddin::ValueObjects::depositFutureValueObject> & valueObject,
                                         //
                                         const bool permanent) : Instrument(valueObject, permanent) {
        
            //libraryObject_ = boost::shared_ptr<QuantLibExtended::depositFuture> (new
            //    QuantLibExtended::depositFuture()) ;

        } ;
            
    }