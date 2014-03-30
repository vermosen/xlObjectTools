/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef daycount_factory_hpp
#define daycount_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/time/daycounter.hpp>

#include <ql/errors.hpp>

namespace ObjectHandler {

    class daycountFactory :
        private RegistryManager<QuantLib::DayCounter, EnumTypeRegistry> {

    public :

        QuantLib::DayCounter operator()(const std::string & id) ; // opérateur de construction
        daycountFactory() ;
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
