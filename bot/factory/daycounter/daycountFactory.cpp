/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/daycounter/daycountFactory.hpp>


namespace ObjectHandler {

    daycountFactory::daycountFactory() {

        idObject = "" ;

    }

    QuantLib::DayCounter daycountFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::DayCounter, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::DayCounter *>(this->getType(id))) ;

            } else {

                    QL_FAIL("unregistered type") ;

                }

    }

    void daycountFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::DayCounter, EnumTypeRegistry>::registerType(i, type) ;

        }

}

