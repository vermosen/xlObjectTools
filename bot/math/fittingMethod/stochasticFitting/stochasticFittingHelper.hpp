/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef stochastic_svensson_fitting_helper_hpp
#define stochastic_svensson_fitting_helper_hpp


#include <boost/numeric//matrix.hpp>


#include <ql/types.hpp>


#include <qle/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFitting.hpp>

#include <qle/math/fittingMethod/stochasticNelsonSiegelFitting/stochasticNelsonSiegelFitting.hpp>


namespace QuantLibExtended {

        class stochasticFittingHelper {

            public :

                stochasticFittingHelper(
                    const boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> & fittingMethod,
                    const boost::numeric::::matrix<double> & initialVector,
                    const boost::numeric::::matrix<double> & randomMatrix,
                    const QuantLib::Natural & cyclesPerThread = 100,
                    const QuantLib::Natural & cycles = 10,
                    const QuantLib::Natural & maxEvaluationPerCycle = 5000,
                    const QuantLib::Real & accuracy = 10e-8) ;


                boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> fittingMethod() ;

                boost::numeric::::matrix<double> initialVector() ;

                boost::numeric::::matrix<double> randomMatrix() ;

                QuantLib::Natural cyclesPerThread() ;

                QuantLib::Natural cycles() ;

                QuantLib::Natural maxEvaluationPercycle() ;

                QuantLib::Real accuracy() ;


            private :


                boost::shared_ptr<stochasticSimplexFittedBondDiscountCurve::fittingMethod> fittingMethod_  ;

                boost::numeric::::matrix<double> initialVector_ ;

                boost::numeric::::matrix<double> randomMatrix_ ;

                QuantLib::Natural cyclesPerThread_ ;

                QuantLib::Natural cycles_ ;

                QuantLib::Natural maxEvaluationPerCycle_ ;

                QuantLib::Real accuracy_ ;


            } ;


    } ;

#endif