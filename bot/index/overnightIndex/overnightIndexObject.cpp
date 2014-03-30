/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/index/overnightindex/overnightIndexObject.hpp>

namespace QuantLibAddin {

		overnightIndexObject::overnightIndexObject(
					 const boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> & properties,
					 const std::string & familyName,
					 const QuantLib::Natural fixingDays,
					 const QuantLib::Calendar & calendar,
					 const QuantLib::DayCounter & dc,
					 const QuantLib::Handle<QuantLib::YieldTermStructure> & hYTS,
					 bool permanent)

			: InterestRateIndex(properties, permanent) {


                libraryObject_ = boost::shared_ptr<QuantLib::OvernightIndex>(new
                    QuantLib::OvernightIndex(familyName, 
                                             fixingDays,
                                             QuantLib::Currency(),
                                             calendar,
                                             dc,
                                             hYTS)) ;

			} ;

        overnightIndexObject::overnightIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> & properties,
                                                   const boost::shared_ptr<QuantLib::OvernightIndex> & myIndex,
								                   bool permanent)

			: InterestRateIndex(properties, permanent) {


                libraryObject_ = myIndex ;

			} ;

	}