/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/period/periodFactory.hpp>

namespace ObjectHandler {

    periodFactory::periodFactory() {

            periodType = "" ;

            periodLen = 0 ;
        
        }

    QuantLib::Period periodFactory::operator()(const std::string & id) {


            periodType = id.substr(id.length() - 1, 1) ;

            stringtoType<QuantLib::Natural>(id.substr(0, id.length() - 1), periodLen) ;

            if (id == "O/N") return QuantLib::Period(1, QuantLib::Days) ;

            if (id == "T/N") return QuantLib::Period(2, QuantLib::Days) ;

            if (id == "S/N") return QuantLib::Period(3, QuantLib::Days) ;

            else if (RegistryManager<QuantLib::TimeUnit, EnumTypeRegistry>::checkType(periodType)) {


                return QuantLib::Period(periodLen, * (static_cast<QuantLib::TimeUnit *>(this->getType(periodType)))) ;


            } else {
                 

                    QL_FAIL("unregistered type") ;


                }

        }

    void periodFactory::registerType(const std::string & i, void * type) {
        
            RegistryManager<QuantLib::TimeUnit, EnumTypeRegistry>::registerType(i, type) ;

        }

}

