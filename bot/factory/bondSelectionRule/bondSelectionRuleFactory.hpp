/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bons_selection_rule_factory_hpp
#define bons_selection_rule_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <qle/termStructure/bondSelectionRule/bondSelectionRule.hpp>

namespace ObjectHandler {

    class bondSelectionRuleFactory :
        private RegistryManager<QuantLibExtended::bondSelectionRule, EnumTypeRegistry> {

    public :

        QuantLibExtended::bondSelectionRule operator()(const std::string & id) ; // opérateur de construction
        
        bondSelectionRuleFactory() ;
        
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
