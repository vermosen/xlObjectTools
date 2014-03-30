/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_create_swap_hpp
#define bot_create_swap_hpp

#include <bot/swap/interestRateSwap/interestRateSwapObject.hpp>

#include <oh/ohdefines.hpp>

#include <oh/object.hpp>

#include <oh/valueobject.hpp>

#include <oh/property.hpp>

#include <oh/enumerations/typefactory.hpp>

#include <qlo/qladdindefines.hpp>

#include <qlo/handle.hpp>

#include <qlo/couponvectors.hpp>

#include <qlo/conversions/all.hpp>

namespace QuantLibAddin {

    boost::shared_ptr<ObjectHandler::Object> create_interestRateSwap(
        const boost::shared_ptr<ObjectHandler::ValueObject> &) ;

}

#endif
