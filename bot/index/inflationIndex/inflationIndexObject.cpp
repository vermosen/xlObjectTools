/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/index/inflationIndex/inflationIndexObject.hpp>

namespace QuantLibAddin {

        inflationIndexObject::inflationIndexObject(
                     const boost::shared_ptr<QuantLibAddin::ValueObjects::inflationIndexValueObject> & properties,
                     const std::string & familyName,
                     const QuantLib::Region & region,
                     const bool revised,
                     const bool interpolated,
                     const QuantLib::Frequency frequency,
                     const QuantLib::Period availabilityLag,
                     const QuantLib::Currency & curncy,
                     const QuantLib::Handle<QuantLib::ZeroInflationTermStructure> & termStr,
                     bool permanent)

        : Index(properties, permanent) {

            libraryObject_ = boost::shared_ptr<QuantLib::Index>(new
                QuantLibExtended::inflationIndex(familyName,
                               region,
                               revised,
                               interpolated,
                               frequency,
                               availabilityLag,
                               curncy, 
                               termStr)) ;

            } ;

        void inflationIndexObject::addFixings(const std::vector<QuantLib::Date> & dates,
                                              const std::vector<QuantLib::Real> & values,
                                              bool forceOverwrite, 
                                              bool updateValuObject) {

                QL_REQUIRE(dates.size()==values.size(),
                           "size mismatch between dates (" << dates.size() <<
                           ") and values (" << values.size() << ")") ;

                std::vector<QuantLib::Date> d ;

                std::vector<QuantLib::Real> v ;

                for (QuantLib::Size i = 0 ; i < values.size() ; ++i) {


                            // skip null fixings
                        if (values[i] != 0.0 && values[i] != QuantLib::Null<QuantLib::Real>()) {


                                QL_REQUIRE(values[i] > 0.0,
                                           "non positive fixing (" << values[i] <<
                                           ") at date " << dates[i] << " not allowed") ;

                                libraryObject_->addFixing(dates[i], values[i], forceOverwrite) ;


                            }

                    }

                if (updateValuObject) {


                        std::vector<long> fixingDates ;

                        std::vector<QuantLib::Real> fixingRates ;

                        const QuantLib::TimeSeries<QuantLib::Real> & history = libraryObject_->timeSeries() ;

                        for (QuantLib::TimeSeries<QuantLib::Real>::const_iterator hi = history.begin() ;
                             hi != history.end() ; ++hi) {


                                fixingDates.push_back(hi->first.serialNumber()) ;

                                fixingRates.push_back(hi->second) ;


                            }

                        boost::shared_ptr<ObjectHandler::ValueObject> instanceProperties = properties() ;

                        instanceProperties->setProperty("IndexFixingDates", fixingDates) ;

                        instanceProperties->setProperty("IndexFixingRates", fixingRates) ;


                    }

            }

    }