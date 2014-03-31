/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingObject.hpp>


namespace QuantLibAddin {


        stochasticFittingObject::stochasticFittingObject(
                        const boost::shared_ptr<QuantLibAddin::ValueObjects::stochasticFittingValueObject> & valueObject,
                        const boost::shared_ptr<QuantLib::stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fitting,
                        const QuantLib::Array & initialVector,
                        const QuantLib::Matrix & randomMatrix,
                        const QuantLib::Natural cyclesPerThread,
                        const QuantLib::Natural cycles,
                        const QuantLib::Natural maxEvaluationPerCycle,
                        const QuantLib::Real accuracy,
                        const bool & permanent) :
    

        ObjectHandler::LibraryObject<QuantLib::stochasticFittingHelper>(valueObject, permanent) {
        
				libraryObject_ = boost::shared_ptr<QuantLib::stochasticFittingHelper> (new
                    QuantLib::stochasticFittingHelper(fitting,
                                                      initialVector,
                                                      randomMatrix,
                                                      cyclesPerThread,
                                                      cycles,
                                                      maxEvaluationPerCycle,
                                                      accuracy)) ;
				
    } ;
     
}