/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef inflation_index_object_hpp
#define inflation_index_object_hpp

#include <qlo/index.hpp>

#include <ql/time/businessdayconvention.hpp>
#include <ql/time/frequency.hpp>

#include <bot/index/inflationIndex/inflationIndexValueObject.hpp>


namespace QuantLib {

        class Period ;
        class Currency ;
        class Region ;
        class Calendar ;
        class ZeroInflationTermStructure ;
        template <class T> class Handle ;


    }

namespace QuantLibAddin {

    class inflationIndexObject : public Index {

            public :

                inflationIndexObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::inflationIndexValueObject> & properties,
                                     const std::string & familyName,
                                     const QuantLib::Region & p,
                                     const bool revised,
                                     const bool interpolated,
                                     const QuantLib::Frequency frequency,
                                     const QuantLib::Period availabilitiyLag,
                                     const QuantLib::Currency & crr,
                                     const QuantLib::Handle<QuantLib::ZeroInflationTermStructure> & ts =
                                        QuantLib::Handle<QuantLib::ZeroInflationTermStructure>(),
                                     bool permanent = false) ;


                void addFixings(const std::vector<QuantLib::Date>& dates,
                                const std::vector<QuantLib::Real>& values,
                                bool forceOverwrite, bool updateValuObject = true) ;

            protected :

                OH_OBJ_CTOR(inflationIndexObject, Index) ;

        } ;

    }

#endif