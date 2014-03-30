/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/12/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveObject.hpp>

namespace QuantLibAddin {

        fittedBondDiscountCurveObject::fittedBondDiscountCurveObject(
            boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve> & curveObject,
            boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> & valueObject,
            const bool permanent) :

        YieldTermStructure(valueObject, permanent) {


                libraryObject_ = curveObject ;


            }

        fittedBondDiscountCurveObject::fittedBondDiscountCurveObject(
            boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> & valueObject,
            const QuantLib::Date & settlementDate,
            const std::vector<boost::shared_ptr<QuantLib::BondHelper> > & instruments,
            const QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod & fittingMethod,
            const boost::numeric::ublas::matrix<double> & guess,
            const boost::numeric::ublas::matrix<double> & matrixRandom,
            const QuantLib::Real accuracy,
            const QuantLib::Size maxEvaluations,
            const QuantLib::Natural cyclesPerThread,
            const QuantLib::Natural evaluationCycles,
            const QuantLib::Real simplexLambda,
            const bool & permanent) :


        YieldTermStructure(valueObject, permanent) {


            boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve> tempCurve (new
                QuantLibExtended::stochasticSimplexFittedBondDiscountCurve(
                     settlementDate,
                     instruments,
                     QuantLib::Actual365Fixed(),
                     fittingMethod,
                     guess,
                     matrixRandom,
                     accuracy,
                     maxEvaluations,
                     cyclesPerThread,
                     evaluationCycles,
                     simplexLambda)) ;

            tempCurve->recalculate() ;

            libraryObject_ = tempCurve ;


            } ;


    }
