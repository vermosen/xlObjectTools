/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/bondSelectionRule/bondSelectionRuleFactory.hpp>


namespace ObjectHandler {


    bondSelectionRuleFactory::bondSelectionRuleFactory() {


            idObject = "" ;


        }


    QuantLibExtended::bondSelectionRule bondSelectionRuleFactory::operator()(const std::string & id) {


            idObject = id ;


            if (RegistryManager<QuantLibExtended::bondSelectionRule, EnumTypeRegistry>::checkType(id)) {


                return * (static_cast<QuantLibExtended::bondSelectionRule *>(this->getType(id))) ;


            } else {


                    std::ostringstream oss ;

                    oss << "unregistered bond selection rule : " << id ;

                    QL_FAIL(oss.str()) ;


                }


        }


    void bondSelectionRuleFactory::registerType(const std::string & i, void * type) {


            RegistryManager<QuantLibExtended::bondSelectionRule, EnumTypeRegistry>::registerType(i, type) ;


        }


}