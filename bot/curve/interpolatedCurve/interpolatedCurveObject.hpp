/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef interpolated_curve_object_hpp
#define interpolated_curve_object_hpp


#include <qlo/termstructures.hpp>


#include <qle/math/interpolator/logCubicInterpolator.hpp>


#include <ql/quotes/futuresconvadjustmentquote.hpp>

#include <ql/indexes/ibor/audlibor.hpp>

#include <ql/termstructures/yield/ratehelpers.hpp>

#include <ql/termstructures/yield/piecewiseyieldcurve.hpp>

#include <ql/time/calendars/australia.hpp>

#include <ql/time/daycounters/actual360.hpp>

#include <ql/time/daycounters/thirty360.hpp>

#include <ql/time/imm.hpp>


#include <bot/curve/interpolatedCurve/interpolatedCurveValueObject.hpp>

#include <bot/factory/period/periodFactory.hpp>


namespace QuantLibAddin {

    class interpolatedCurveObject : public YieldTermStructure {

        public :

            interpolatedCurveObject(boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedCurveValueObject> & valueObject,
                                    const QuantLib::Date & calculationDate,
                                    const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
                                    const bool & permanent = true,
                                    const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps
                                        = std::vector<QuantLib::Handle<QuantLib::Quote> >(),
                                    const std::vector<QuantLib::Date> & jumpDates
                                        = std::vector<QuantLib::Date>(),
                                    QuantLib::Real accuracy = 1.0e-8) ;


        } ;

    }

#endif
