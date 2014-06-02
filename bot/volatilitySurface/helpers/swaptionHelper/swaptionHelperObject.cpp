/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
Copyright (C) 2006, 2007, 2008, 2009, 2012 Ferdinando Ametrano
Copyright (C) 2006, 2007 Marco Bianchetti
Copyright (C) 2005 Aurelien Chanudet
Copyright (C) 2005, 2006, 2007 Eric Ehlers
Copyright (C) 2005 Plamen Neykov

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include "bot/volatilitySurface/helpers/swaptionHelper/swaptionHelperObject.hpp"

namespace QuantLibAddin {

	SwaptionHelperObject::SwaptionHelperObject(
		const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		const QuantLib::Period & maturity,
		const QuantLib::Period & length,
		const QuantLib::Handle<QuantLib::Quote> & volatility,
		const boost::shared_ptr<QuantLib::IborIndex> & index,
		const QuantLib::Period & fixedLegTenor,
		const QuantLib::DayCounter & fixedLegDayCounter,
		const QuantLib::DayCounter & floatingLegDayCounter,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& termStructure,
		QuantLib::CalibrationHelper::CalibrationErrorType errorType,
		const QuantLib::Real strike,
		const QuantLib::Real nominal,
		bool permanent) : CalibrationHelper(properties, permanent) {

		libraryObject_ = boost::shared_ptr<QuantLib::CalibrationHelper>(new
			QuantLib::SwaptionHelper(
			maturity,
			length,
			volatility,
			index,
			fixedLegTenor,
			fixedLegDayCounter,
			floatingLegDayCounter,
			termStructure,
			errorType,
			strike,
			nominal));

	}

}