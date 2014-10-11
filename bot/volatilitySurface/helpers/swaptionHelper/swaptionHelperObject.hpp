/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_swaption_helper_object
#define bot_swaption_helper_object

#include <ql/models/shortrate/calibrationhelpers/swaptionhelper.hpp>

#include <qlo/calibrationhelper.hpp>

#include <bot/volatilitySurface/helpers/swaptionHelper/swaptionHelperValueObject.hpp>

namespace QuantLibAddin {

	class SwaptionHelperObject : public CalibrationHelper {
	
	public:
	
		SwaptionHelperObject(
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
			const QuantLib::Real strike = QuantLib::Null<QuantLib::Real>(),
			const QuantLib::Real nominal = 1.0,
			bool permanent = true);

		SwaptionHelperObject(
			const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const QuantLib::Date & exerciceDate,
			const QuantLib::Date & endDate,
			const QuantLib::Handle<QuantLib::Quote> & volatility,
			const boost::shared_ptr<QuantLib::IborIndex> & index,
			const QuantLib::Period & fixedLegTenor,
			const QuantLib::DayCounter & fixedLegDayCounter,
			const QuantLib::DayCounter & floatingLegDayCounter,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& termStructure,
			QuantLib::CalibrationHelper::CalibrationErrorType errorType,
			const QuantLib::Real strike = QuantLib::Null<QuantLib::Real>(),
			const QuantLib::Real nominal = QuantLib::Null<QuantLib::Real>(),
			bool permanent = true);

	};

}

#endif