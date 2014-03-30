/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef period_factory_hpp
#define period_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/time/period.hpp>

#include <ql/errors.hpp>

#include <bot/tools/stringtoType/stringtoType.hpp>

namespace ObjectHandler {

    class periodFactory :

        private RegistryManager<QuantLib::TimeUnit, EnumTypeRegistry> {

    public :

        QuantLib::Period operator()(const std::string & id) ; // opérateur de construction

        periodFactory() ;

        void registerType(const std::string &, void *) ; // ici on register seulement le timeUnit

    private :

        std::string periodType ;

        QuantLib::Natural periodLen ;

    } ;

 }

#endif
