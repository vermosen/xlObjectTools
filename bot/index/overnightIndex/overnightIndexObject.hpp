/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef overnight_index_object_hpp
#define overnight_index_object_hpp

#include <qlo/indexes/interestrateindex.hpp>

#include <ql/time/businessdayconvention.hpp>

#include <ql/indexes/IborIndex.hpp>

#include <bot/index/overnightIndex/overnightIndexValueObject.hpp>


namespace QuantLibAddin {

		class overnightIndexObject : public InterestRateIndex {
		      
				public :

		            overnightIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> & properties,
					                     const std::string & familyName,
					                     const QuantLib::Natural fixingDays,
					                     const QuantLib::Calendar & calendar,
					                     const QuantLib::DayCounter & dc,
					                     const QuantLib::Handle<QuantLib::YieldTermStructure> & hYTS,
					                     bool permanent) ;
			      
					overnightIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> & properties,
                                         const boost::shared_ptr<QuantLib::OvernightIndex> & myIndex,
									     bool permanent) ;

				protected:

					OH_OBJ_CTOR(overnightIndexObject, InterestRateIndex) ;

			} ;


    }

#endif