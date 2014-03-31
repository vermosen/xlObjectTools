/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 09/05/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/interpolatedZeroSpreadedTermStructure/interpolatedZeroSpreadedTermStructureObject.hpp>

namespace QuantLibAddin {

    interpolatedZeroSpreadedTermStructureObject::interpolatedZeroSpreadedTermStructureObject (
                boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedZeroSpreadedTermStructureValueObject> & valueObject,
                const QuantLib::Handle<QuantLib::YieldTermStructure> & baseCurve,
                const std::vector<QuantLib::Handle<QuantLib::gapQuote> > & gapQuotes,
                const bool & permanent) : YieldTermStructure(valueObject, permanent) {


                    libraryObject_ = boost::shared_ptr<QuantLib::interpolatedZeroSpreadedTermStructure> (new
                        QuantLib::interpolatedZeroSpreadedTermStructure(baseCurve, gapQuotes)) ;


                }

        }
