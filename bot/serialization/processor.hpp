/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_processor_hpp
#define bot_processor_hpp


#include <oh/repository.hpp>

#include <oh/processor.hpp>

//#include <qlo/handle.hpp>

//#include <qlo/pricingengines.hpp>

//#include <qlo/leg.hpp>

#include <qlo/couponvectors.hpp>

#include <qlo/conversions/varianttodate.hpp>

//#include <qlo/extrapolator.hpp>

//#include <qlo/baseinstruments.hpp>

//#include <qlo/index.hpp>

namespace QuantLibAddin {

        class legProcessor : public ObjectHandler::Processor {

                std::string process(const ObjectHandler::SerializationFactory & factory,
                                    const boost::shared_ptr<ObjectHandler::ValueObject> & valueObject,
                                    bool overwriteExisting) const ;

                void postProcess() const {}

            } ;


    }

#endif
