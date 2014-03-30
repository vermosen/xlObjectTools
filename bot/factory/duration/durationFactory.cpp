/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/duration/durationFactory.hpp>

namespace ObjectHandler {

    durationFactory::durationFactory() {

        idObject = "" ;

    }

    QuantLib::Duration::Type durationFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Duration::Type, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Duration::Type *>(this->getType(id))) ;

            } else {

                    throw std::string("unregistered type") ;

                }

    }

    void durationFactory::registerType(const std::string & i, void * type) {

        RegistryManager<QuantLib::Duration::Type, EnumTypeRegistry>::registerType(i, type) ;

        }

}

