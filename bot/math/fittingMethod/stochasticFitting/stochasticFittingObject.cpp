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
                        const boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fitting,
                        const boost::numeric::::matrix<double> initialVector,
                        const boost::numeric::::matrix<double> randomMatrix,
                        const QuantLib::Natural cyclesPerThread,
                        const QuantLib::Natural cycles,
                        const QuantLib::Natural maxEvaluationPerCycle,
                        const QuantLib::Real accuracy,
                        const bool & permanent) :
    

        ObjectHandler::LibraryObject<QuantLibExtended::stochasticFittingHelper>(valueObject, permanent) {
        

                libraryObject_ = boost::shared_ptr<QuantLibExtended::stochasticFittingHelper> (new
                    QuantLibExtended::stochasticFittingHelper(fitting,
                                                                      initialVector,
                                                                      randomMatrix,
                                                                      cyclesPerThread,
                                                                      cycles,
                                                                      maxEvaluationPerCycle,
                                                                      accuracy)) ;


    } ;
     

}