/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#ifndef us_swap_curve_object_hpp
#define us_swap_curve_object_hpp

#include <qlo/termstructures.hpp>

#include <ql/quotes/futuresconvadjustmentquote.hpp>
#include <ql/indexes/ibor/usdlibor.hpp>
#include <ql/termstructures/yield/ratehelpers.hpp>
#include <ql/time/calendars/unitedstates.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/time/daycounters/thirty360.hpp>
#include <ql/time/imm.hpp>

#include <qle/quotes/futuresConvexityAdjustmentQuote/futuresConvexityAdjustmentQuote.hpp>
#include <qle/termStructure/swapCurveUnitedStates/swapCurveUnitedStates.hpp>

#include <bot/curve/swapCurveUnitedStates/swapCurveUnitedStatesValueObject.hpp>
#include <bot/factory/period/periodFactory.hpp>

namespace QuantLibAddin {

    class swapCurveUnitedStatesObject : public YieldTermStructure {

    public :

        swapCurveUnitedStatesObject(boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject> & valueObject,
                          const QuantLib::Date & calculationDate,
                          const std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > & instruments,
                          const bool & permanent = true,
                          const std::vector<QuantLib::Handle<QuantLib::Quote> > & jumps
                              = std::vector<QuantLib::Handle<QuantLib::Quote> >(),
                          const std::vector<QuantLib::Date> & jumpDates
                              = std::vector<QuantLib::Date>(),
                          QuantLib::Real accuracy = 1.0e-8) ;

        swapCurveUnitedStatesObject(boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject> & valueObject,
                          const QuantLib::Date & calculationDate,
                          const std::vector <std::string> & instrumentTag,
                          const std::vector <std::string> & maturityTag,
                          const std::vector <double> & quote,
                          const QuantLib::Real & convexityFactor,
						  const boost::shared_ptr<QuantLib::IborIndex> & liborIndex, // laissé non const pour modification du lien
                          const QuantLib::Real & meanReversionFactor = 0.03,
                          const bool & permanent = true,
                          const QuantLib::Real & accuracy = 1.0e-8) ;

        } ;

    }

#endif
