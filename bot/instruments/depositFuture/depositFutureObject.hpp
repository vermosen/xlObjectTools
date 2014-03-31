/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef deposit_future_object
#define deposit_future_object

#include <qlo/baseinstruments.hpp>

#include <ql/instruments/depositFuture.hpp>

#include <bot/instruments/depositFuture/depositFutureValueObject.hpp>

namespace QuantLibAddin {

    class depositFutureObject : public Instrument {

    public :

            depositFutureObject::depositFutureObject(
				boost::shared_ptr<QuantLibAddin::ValueObjects::depositFutureValueObject> & valueObject,
                const bool permanent = true) ;

        } ;

    }

#endif