/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef currency_factory_hpp
#define currency_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/currency.hpp>

#include <ql/errors.hpp>

namespace ObjectHandler {

    class currencyFactory :
        private RegistryManager<QuantLib::Currency, EnumTypeRegistry> {

    public :

        QuantLib::Currency operator()(const std::string & id) ; // opérateur de construction
        currencyFactory() ;
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
