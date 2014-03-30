/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/calendar/calendarFactory.hpp>

namespace ObjectHandler {

    calendarFactory::calendarFactory() {

            idObject = "" ;

        }

    QuantLib::Calendar calendarFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Calendar, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Calendar *>(this->getType(id))) ;

            } else {

                    std::ostringstream oss ;
                    oss << "unregistered calendar : " << id ;
                    QL_FAIL(oss.str()) ;

                }

        }

    void calendarFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::Calendar, EnumTypeRegistry>::registerType(i, type) ;

        }

}

