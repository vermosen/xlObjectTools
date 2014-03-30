/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/compounding/compoundingFactory.hpp>

namespace ObjectHandler {

    compoundingFactory::compoundingFactory() {

        idObject = "" ;

    }

    QuantLib::Compounding compoundingFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Compounding, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Compounding *>(this->getType(id))) ;

            } else {

                    std::ostringstream oss ;

                    oss << "unregistered compounding : " << id ;

                    QL_FAIL(oss.str()) ;

                }

    }

    void compoundingFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::Compounding, EnumTypeRegistry>::registerType(i, type) ;

        }

}

