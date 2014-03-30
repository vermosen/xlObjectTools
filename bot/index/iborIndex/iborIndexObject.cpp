/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/index/iborindex/iborIndexObject.hpp>

namespace QuantLibAddin {

		iborIndexObject::iborIndexObject(
					 const boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> & properties,
					 const std::string & familyName,
					 const QuantLib::Period & p,
					 const QuantLib::Natural fixingDays,
					 const QuantLib::Calendar & calendar,
					 QuantLib::BusinessDayConvention fltBDC,
					 bool endOfMonth,
					 const QuantLib::DayCounter & fltDayCounter,
					 const QuantLib::Handle<QuantLib::YieldTermStructure> & hYTS,
					 bool permanent)

			: InterestRateIndex(properties, permanent) {


                libraryObject_ = boost::shared_ptr<QuantLib::IborIndex>(new
                    QuantLib::IborIndex(familyName, 
                                        p,
                                        fixingDays, 
                                        QuantLib::Currency(), // dummy currency
                                        calendar, 
                                        fltBDC, 
                                        endOfMonth, 
                                        fltDayCounter,
                                        hYTS));


			} ;

		iborIndexObject::iborIndexObject(
					 const boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> & properties,
                     const boost::shared_ptr<QuantLib::IborIndex> & myIndex,
					 bool permanent)

			: InterestRateIndex(properties, permanent) {
			
				libraryObject_ = myIndex ;
			
			} ;

	}