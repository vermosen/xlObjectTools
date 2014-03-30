/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/serialization/processor.hpp>


namespace QuantLibAddin {


        std::string legProcessor::process(const ObjectHandler::SerializationFactory & factory,
                                          const boost::shared_ptr<ObjectHandler::ValueObject> & valueObject,
                                          bool overwriteExisting) const {
            
                ObjectHandler::StrObjectPair object = factory.restoreObject(valueObject, overwriteExisting) ;

                boost::shared_ptr<Leg> inst = boost::dynamic_pointer_cast<Leg>(object.second) ;

                if (inst && valueObject->hasProperty("UserLegIDs")) {

                        std::vector<boost::shared_ptr<QuantLibAddin::FloatingRateCouponPricer> > legs2 ;

                        std::vector<std::string> legs =
                            ObjectHandler::vector::convert2<std::string>(valueObject->getProperty("UserLegIDs"), "UserLegIDs") ;

                        for (std::vector<std::string>::const_iterator i = legs.begin() ; i != legs.end() ; ++i) {

                                OH_GET_OBJECT(leg, * i, QuantLibAddin::FloatingRateCouponPricer)

                                legs2.push_back(leg) ;

                            }

                        inst->setCouponPricers(legs2) ;

                    }
                            
                    return object.first ;

            }


    }
