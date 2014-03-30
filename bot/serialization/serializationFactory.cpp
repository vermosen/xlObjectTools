/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/serialization/serializationFactory.hpp>


#include <bot/serialization/create/create_all.hpp>

#include <bot/serialization/processor.hpp>

#include <bot/serialization/register/serialization_register.hpp>


#include <boost/serialization/vector.hpp>

#include <boost/serialization/shared_ptr.hpp>

namespace QuantLibAddin {

    serializationFactory::serializationFactory() {

        registerCreators() ;

        ObjectHandler::ProcessorPtr legProcessor(new legProcessor()) ;

        ObjectHandler::ProcessorFactory::instance().storeProcessor(
			"LegProcessor", legProcessor) ;


    }

    void serializationFactory::register_out(boost::archive::xml_oarchive & ar,
        std::vector<boost::shared_ptr<ObjectHandler::ValueObject> > & valueObjects){

            tpl_register_classes(ar) ;

            ar << boost::serialization::make_nvp("object_list", valueObjects) ;

    }


    void serializationFactory::register_in(boost::archive::xml_iarchive & ar,
        std::vector<boost::shared_ptr<ObjectHandler::ValueObject> > & valueObjects){

            tpl_register_classes(ar) ;

            ar >> boost::serialization::make_nvp("object_list", valueObjects) ;

    }


}

