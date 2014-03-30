/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef frequency_factory_hpp
#define frequency_factory_hpp

#include <oh/enumerations/typefactory.hpp>

#include <ql/time/frequency.hpp>

#include <ql/errors.hpp>

namespace ObjectHandler {

    class frequencyFactory : private RegistryManager<QuantLib::Frequency, EnumTypeRegistry> {

    public :

        QuantLib::Frequency operator()(const std::string & id) ; // opérateur de construction

        QuantLib::Frequency operator()(const int & id) ; // spécial case int

        frequencyFactory() ;

        void registerType(const std::string &, void *) ;

        void registerType(const int &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
