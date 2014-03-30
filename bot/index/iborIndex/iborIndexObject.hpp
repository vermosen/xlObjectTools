/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef ibor_index_object_hpp
#define ibor_index_object_hpp

#include <qlo/indexes/interestrateindex.hpp>


#include <ql/time/businessdayconvention.hpp>

#include <ql/indexes/IborIndex.hpp>


#include <bot/index/iborIndex/iborIndexValueObject.hpp>


//namespace QuantLib {
//
//
//		class Period ;
//
//		class Currency ;
//		
//		class Calendar ;
//		
//		class DayCounter ;
//		
//		class YieldTermStructure ;
//
//		template <class T>
//		class Handle ;
//	
//
//	}

namespace QuantLibAddin {

		class iborIndexObject : public InterestRateIndex {
		      
				public :

					iborIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> & properties,
								    const std::string & familyName,
								    const QuantLib::Period & p,
								    const QuantLib::Natural fixingDays,
								    const QuantLib::Calendar & calendar,
								    QuantLib::BusinessDayConvention fltBDC,
								    bool endOfMonth,
								    const QuantLib::DayCounter & fltDayCounter,
								    const QuantLib::Handle<QuantLib::YieldTermStructure> & hYTS,
								    bool permanent) ;
			      
					iborIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> & properties,
                                    const boost::shared_ptr<QuantLib::IborIndex> & myIndex,
									bool permanent) ;

				protected:

					OH_OBJ_CTOR(iborIndexObject, InterestRateIndex) ;

			} ;


    }

#endif