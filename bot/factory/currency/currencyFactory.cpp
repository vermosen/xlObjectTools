/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/currency/currencyFactory.hpp>

namespace ObjectHandler {

    currencyFactory::currencyFactory() {

            idObject = "" ;

        }

    QuantLib::Currency currencyFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Currency, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Currency *>(this->getType(id))) ;

            } else {

                    std::ostringstream oss ;
                    oss << "unregistered calendar  : " << id ;
                    QL_FAIL(oss.str()) ;

                }

        }

    void currencyFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::Currency, EnumTypeRegistry>::registerType(i, type) ;

        }

}

