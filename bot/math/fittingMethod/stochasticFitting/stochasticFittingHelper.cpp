/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingHelper.hpp>

namespace QuantLib {

        stochasticFittingHelper::stochasticFittingHelper(
                               const boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fittingMethod,
                               const Array & initialVector,
                               const Matrix & randomMatrix,
                               const Natural & cyclesPerThread,
                               const Natural & cycles,
                               const Natural & maxEvaluationPerCycle,
                               const Real & accuracy) :

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


        Array stochasticFittingHelper::initialVector() {
                    
                        
                return initialVector_ ;


            }


        Matrix stochasticFittingHelper::randomMatrix() {
                    
                        
                return randomMatrix_ ;


            }

        Natural stochasticFittingHelper::cyclesPerThread() {
                    
                        
                return cyclesPerThread_ ;


            }


        Natural stochasticFittingHelper::cycles() {
                    
                        
                return cycles_ ;


            }

        Natural stochasticFittingHelper::maxEvaluationPercycle() {
                    
                        
                return maxEvaluationPerCycle_ ;


            }

        Real stochasticFittingHelper::accuracy() {
                    
                        
                return accuracy_ ;


            }


    }