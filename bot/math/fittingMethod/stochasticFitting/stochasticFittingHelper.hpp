/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef stochastic_svensson_fitting_helper_hpp
#define stochastic_svensson_fitting_helper_hpp

#include <ql/types.hpp>

#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFitting.hpp>
#include <ql/experimental/math/fittingMethod/stochasticNelsonSiegelFitting/stochasticNelsonSiegelFitting.hpp>


namespace QuantLib {

        class stochasticFittingHelper {

            public :

                stochasticFittingHelper(
                    const boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fittingMethod,
                    const Array & initialVector,
                    const Matrix & randomMatrix,
                    const Natural & cyclesPerThread = 100,
                    const Natural & cycles = 10,
                    const Natural & maxEvaluationPerCycle = 5000,
                    const Real & accuracy = 10e-8) ;


                boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> fittingMethod() ;

                Array initialVector() ;
                Matrix randomMatrix() ;
                Natural cyclesPerThread() ;
                Natural cycles() ;
                Natural maxEvaluationPercycle() ;
                Real accuracy() ;

            private :

                boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> fittingMethod_  ;

                Array initialVector_ ;
				Matrix randomMatrix_ ;
                Natural cyclesPerThread_ ;
                Natural cycles_ ;
                Natural maxEvaluationPerCycle_ ;
                Real accuracy_ ;

            } ;

    } ;

#endif