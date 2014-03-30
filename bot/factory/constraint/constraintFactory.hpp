/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef constraint_factory_hpp
#define constraint_factory_hpp


#include <oh/enumerations/typefactory.hpp>

#include <ql/math/optimization/constraint.hpp>

#include <ql/errors.hpp>


namespace ObjectHandler {


        class constraintFactory : private RegistryManager<QuantLib::Constraint, EnumTypeRegistry> {


            public :


                QuantLib::Constraint operator()(const std::string & id) ; // opérateur de construction

                constraintFactory() ;

                void registerType(const std::string &, void *) ;


            private :


                std::string idObject ;


            } ;


        }

#endif
