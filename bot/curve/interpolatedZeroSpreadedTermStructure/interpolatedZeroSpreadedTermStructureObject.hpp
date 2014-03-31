/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 09/05/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef interpolated_zero_spreaded_term_structure_object_hpp
#define interpolated_zero_spreaded_term_structure_object_hpp

#include <qlo/termstructures.hpp>

#include <bot/curve/interpolatedZeroSpreadedTermStructure/interpolatedZeroSpreadedTermStructureValueObject.hpp>

#include <ql/experimental/termStructures/yield/interpolatedZeroSpreadedTermStructure.hpp>

namespace QuantLibAddin {

    class interpolatedZeroSpreadedTermStructureObject : public YieldTermStructure {

            public :

                interpolatedZeroSpreadedTermStructureObject::interpolatedZeroSpreadedTermStructureObject(
                    boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedZeroSpreadedTermStructureValueObject> & valueObject,
                    const QuantLib::Handle<QuantLib::YieldTermStructure> & baseCurve,
                    const std::vector<QuantLib::Handle<QuantLib::gapQuote> > & gapQuotes,
                    const bool & permanent = true) ;


        } ;


    }

#endif

