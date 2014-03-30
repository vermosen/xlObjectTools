/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/constraint/constraintFactory.hpp>

namespace ObjectHandler {

    constraintFactory::constraintFactory() {

            idObject = "" ;

        }

    QuantLib::Constraint constraintFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Constraint, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Constraint *>(this->getType(id))) ;

            } else {

                    QL_FAIL("unregistered type") ;

                }

        }

    void constraintFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::Constraint, EnumTypeRegistry>::registerType(i, type) ;

        }

}
