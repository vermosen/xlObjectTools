/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef swap_curve_australia_object_hpp
#define swap_curve_australia_object_hpp


#include <qlo/termstructures.hpp>

#include <ql/quotes/futuresconvadjustmentquote.hpp>
#include <ql/indexes/ibor/audlibor.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
#include <ql/time/calendars/australia.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>
#include <ql/time/imm.hpp>
#include <ql/quotes/futuresConvexityAdjustmentQuote2.hpp>

#include <qle/termStructure/swapCurveAustralia/swapCurveAustralia.hpp>

#include <bot/curve/swapCurveAustralia/swapCurveAustraliaValueObject.hpp>
#include <bot/factory/period/periodFactory.hpp>

namespace QuantLibAddin {

    class swapCurveAustraliaObject : public YieldTermStructure {

    public :

        swapCurveAustraliaObject(boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject> & valueObject,
                          const QuantLib::Date & calculationDate,
                          const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
                          const bool & permanent = true,
                          const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps
                              = std::vector<QuantLib::Handle<QuantLib::Quote> >(),
                          const std::vector<QuantLib::Date> & jumpDates
                              = std::vector<QuantLib::Date>(),
                          QuantLib::Real accuracy = 1.0e-8) ;

        swapCurveAustraliaObject(boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject> & valueObject,
                          const QuantLib::Date & calculationDate,
                          const std::vector <std::string> & instrumentTag,
                          const std::vector <std::string> & maturityTag,
                          const std::vector <double> & quote,
                          const QuantLib::Real & convexityFactor,
						  const boost::shared_ptr<QuantLib::IborIndex> & liborIndex3M,
                          const boost::shared_ptr<QuantLib::IborIndex> & liborIndex6M,
                          const QuantLib::Real & meanReversionFactor = 0.03,
                          const bool & permanent = true,
                          const QuantLib::Real & accuracy = 1.0e-8) ;

        } ;

    }

#endif
