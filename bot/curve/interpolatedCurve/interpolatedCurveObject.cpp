/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/interpolatedCurve/interpolatedCurveObject.hpp>

namespace QuantLibAddin {


        interpolatedCurveObject::interpolatedCurveObject(
	        boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedCurveValueObject> & valueObject,
            const QuantLib::Date & calculationDate,
            const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
            const bool & permanent,
            const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps,
            const std::vector<QuantLib::Date> & jumpDates,
            QuantLib::Real accuracy) :

            YieldTermStructure(valueObject, permanent) {

                libraryObject_ = boost::shared_ptr<QuantLib::PiecewiseYieldCurve<QuantLib::Discount, QuantLib::logCubicInterpolator> > (new
					    QuantLib::PiecewiseYieldCurve<QuantLib::Discount, QuantLib::logCubicInterpolator>(calculationDate,
												                                                          instruments,
                                                                                                          QuantLib::Actual365Fixed(),
												                                                          accuracy)) ;

            }


    }
