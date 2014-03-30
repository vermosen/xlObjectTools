/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef calendar_factory_hpp
#define calendar_factory_hpp

#include <oh/enumerations/typefactory.hpp>
#include <ql/time/calendars/jointcalendar.hpp>
#include <ql/errors.hpp>

namespace ObjectHandler {

    class calendarFactory :
        private RegistryManager<QuantLib::Calendar, EnumTypeRegistry> {

    public :

        QuantLib::Calendar operator()(const std::string & id) ; // opérateur de construction
        calendarFactory() ;
        void registerType(const std::string &, void *) ;

    private :

        std::string idObject ;

    } ;

 }

#endif
