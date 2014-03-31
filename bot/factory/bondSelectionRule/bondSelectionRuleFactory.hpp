/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bond_selection_rule_factory_hpp
#define bond_selection_rule_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/utilities/bondSelectionRule.hpp>

namespace ObjectHandler {

    class bondSelectionRuleFactory :
        private RegistryManager<QuantLib::bondSelectionRule, EnumTypeRegistry> {

    public :

        QuantLib::bondSelectionRule operator()(const std::string & id) ; // opérateur de construction
        
        bondSelectionRuleFactory() ;
        
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
