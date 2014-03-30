/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/curveShift/curveShiftObject.hpp>

namespace QuantLibAddin {

    curveShiftObject::curveShiftObject(boost::shared_ptr<QuantLibAddin::ValueObjects::curveShiftValueObject> & vo,
                                       const std::vector<QuantLib::Handle<QuantLib::gapQuote> > & quotes,
                                       const bool & permanent) : gapSet(vo, permanent) {

            curveShift_ = quotes ;

        } ;

    std::vector<QuantLib::Handle<QuantLib::gapQuote> > curveShiftObject::getcurveShift() const {

            return curveShift_ ;

        }

}