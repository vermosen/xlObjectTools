/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/12/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef fitted_bond_discount_curve_object_hpp
#define fitted_bond_discount_curve_object_hpp


#include <ql/time/calendars/australia.hpp>
#include <ql/termstructures/yield/nonlinearfittingmethods.hpp>

#include <qlo/termstructures.hpp>

#include <boost/numeric/ublas/matrix.hpp>

#include <qle/termStructure/stochasticSimplexFittedBondDiscountCurve/stochasticSimplexFittedBondDiscountCurve.hpp>

#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveValueObject.hpp>


namespace QuantLibAddin {

    class fittedBondDiscountCurveObject : public YieldTermStructure {

    public :


            // copy ctor
        fittedBondDiscountCurveObject(
            boost::shared_ptr<QuantLibExtended::stochasticSimplexFittedBondDiscountCurve> & curveObject,
            boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> & valueObject,
            const bool permanent = true) ;


            // full ctor
        fittedBondDiscountCurveObject(
            boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> & valueObject,
            const QuantLib::Date & settlementDate,
            const std::vector<boost::shared_ptr<QuantLib::BondHelper> > & instruments,
            const QuantLibExtended::stochasticSimplexFittedBondDiscountCurve::fittingMethod & fittingMethod,
            const boost::numeric::ublas::matrix<double> & guess,
            const boost::numeric::ublas::matrix<double> & randomMatrix,
            const QuantLib::Real accuracy = 1.0e-10,
            const QuantLib::Size maxEvaluations = 10000,
            const QuantLib::Natural cyclesPerThread = 1,
            const QuantLib::Natural evaluationCycles = 1,
            const QuantLib::Real simplexLambda = 1.0000,
            const bool & permanent = true) ;


        } ;

    }

#endif
