/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>


namespace ObjectHandler {


    businessDayConventionFactory::businessDayConventionFactory() {


            idObject = "" ;


        }


    QuantLib::BusinessDayConvention businessDayConventionFactory::operator()(const std::string & id) {


            idObject = id ;


            if (RegistryManager<QuantLib::BusinessDayConvention, EnumTypeRegistry>::checkType(id)) {


                return * (static_cast<QuantLib::BusinessDayConvention *>(this->getType(id))) ;


            } else {


                    std::ostringstream oss ;

                    oss << "unregistered business day convention : " << id ;

                    QL_FAIL(oss.str()) ;


                }


        }


    void businessDayConventionFactory::registerType(const std::string & i, void * type) {


            RegistryManager<QuantLib::BusinessDayConvention, EnumTypeRegistry>::registerType(i, type) ;


        }


}