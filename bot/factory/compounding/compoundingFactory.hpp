/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef compounding_factory_hpp
#define compounding_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/compounding.hpp>

#include <ql/errors.hpp>

namespace ObjectHandler {

    class compoundingFactory :
        private RegistryManager<QuantLib::Compounding, EnumTypeRegistry> {

    public :

        QuantLib::Compounding operator()(const std::string & id) ; // opérateur de construction

        compoundingFactory() ;

        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
