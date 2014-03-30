/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef duration_factory_hpp
#define duration_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/cashflows/duration.hpp>

#include <ql/errors.hpp>

namespace ObjectHandler {

    class durationFactory : private RegistryManager<QuantLib::Duration::Type, EnumTypeRegistry> {

    public :

        QuantLib::Duration::Type operator()(const std::string & id) ; // opérateur de construction
        
        durationFactory() ;
        
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif

