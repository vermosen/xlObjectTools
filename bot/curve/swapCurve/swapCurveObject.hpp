/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef swap_curve_object_hpp
#define swap_curve_object_hpp

#include <qlo/termstructures.hpp>
#include <ql/termStructures/yield/swapCurve.hpp>

#include <bot/curve/swapCurve/swapCurveValueObject.hpp>

namespace QuantLibAddin {

    class swapCurveObject : public YieldTermStructure {

    public :

		// TODO : add a second ctor
        swapCurveObject(boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveValueObject> & valueObject,
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
