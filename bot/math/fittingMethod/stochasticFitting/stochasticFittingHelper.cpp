/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingHelper.hpp>

namespace QuantLibExtended {

        stochasticFittingHelper::stochasticFittingHelper(
                               const boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fittingMethod,
                               const boost::numeric::::matrix<double> & initialVector,
                               const boost::numeric::::matrix<double> & randomMatrix,
                               const QuantLib::Natural & cyclesPerThread,
                               const QuantLib::Natural & cycles,
                               const QuantLib::Natural & maxEvaluationPerCycle,
                               const QuantLib::Real & accuracy) :

                fittingMethod_(fittingMethod),
                initialVector_(initialVector),
                randomMatrix_(randomMatrix),
                cyclesPerThread_(cyclesPerThread),
                cycles_(cycles),
                maxEvaluationPerCycle_(maxEvaluationPerCycle),
                accuracy_(accuracy) {} ;

        boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> stochasticFittingHelper::fittingMethod() {
                    
                        
                return fittingMethod_ ;


            }


        boost::numeric::::matrix<double> stochasticFittingHelper::initialVector() {
                    
                        
                return initialVector_ ;


            }


        boost::numeric::::matrix<double> stochasticFittingHelper::randomMatrix() {
                    
                        
                return randomMatrix_ ;


            }

        QuantLib::Natural stochasticFittingHelper::cyclesPerThread() {
                    
                        
                return cyclesPerThread_ ;


            }


        QuantLib::Natural stochasticFittingHelper::cycles() {
                    
                        
                return cycles_ ;


            }

        QuantLib::Natural stochasticFittingHelper::maxEvaluationPercycle() {
                    
                        
                return maxEvaluationPerCycle_ ;


            }

        QuantLib::Real stochasticFittingHelper::accuracy() {
                    
                        
                return accuracy_ ;


            }


    }