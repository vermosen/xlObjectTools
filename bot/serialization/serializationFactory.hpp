/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_serialization_factory_hpp
#define bot_serialization_factory_hpp

#include <oh/ohdefines.hpp>

#include <oh/serializationfactory.hpp>

namespace QuantLibAddin {

    class serializationFactory : public ObjectHandler::SerializationFactory {

    public:

        serializationFactory() ;

    private:

        void registerCreators() ;

        virtual void register_out(boost::archive::xml_oarchive & ar,
            std::vector<boost::shared_ptr<ObjectHandler::ValueObject> > & valueObjects) ;

        virtual void register_in(boost::archive::xml_iarchive & ar,
            std::vector<boost::shared_ptr<ObjectHandler::ValueObject> > & valueObjects) ;

    } ;

}

#endif

