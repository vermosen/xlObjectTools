/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */



#ifndef stochastic_fitting_object_hpp
#define stochastic_fitting_object_hpp


#include <oh/libraryobject.hpp>

#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingHelper.hpp>

#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingValueObject.hpp>


namespace QuantLibAddin {


        class stochasticFittingObject : public ObjectHandler::LibraryObject<QuantLibExtended::stochasticFittingHelper> {


                public :


                    stochasticFittingObject(
                        const boost::shared_ptr<QuantLibAddin::ValueObjects::stochasticFittingValueObject> & valueObject,
                        const boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fitting,
                        const boost::numeric::::matrix<double> initialVector,
                        const boost::numeric::::matrix<double> randomMatrix,
                        const QuantLib::Natural cyclesPerThread = 1,
                        const QuantLib::Natural cycles = 1,
                        const QuantLib::Natural maxEvaluationPerCycle = 5000,
                        const QuantLib::Real accuracy = 10e-8,
                        const bool & permanent = true) ;


            } ;


    }


#endif