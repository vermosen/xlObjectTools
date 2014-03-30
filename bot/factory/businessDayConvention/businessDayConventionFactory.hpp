/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef business_day_convention_factory_hpp
#define business_day_convention_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/time/businessdayconvention.hpp>
#include <ql/errors.hpp>

namespace ObjectHandler {

    class businessDayConventionFactory :
        private RegistryManager<QuantLib::BusinessDayConvention, EnumTypeRegistry> {

    public :

        QuantLib::BusinessDayConvention operator()(const std::string & id) ; // opérateur de construction
        businessDayConventionFactory() ;
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
