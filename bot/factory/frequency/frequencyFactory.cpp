/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/frequency/frequencyFactory.hpp>

namespace ObjectHandler {

    frequencyFactory::frequencyFactory() {

        idObject = "" ;

    }

    QuantLib::Frequency frequencyFactory::operator()(const std::string & id) {

            idObject = id ;

            if (RegistryManager<QuantLib::Frequency, EnumTypeRegistry>::checkType(id)) { // already registered

                return * (static_cast<QuantLib::Frequency *>(this->getType(id))) ;

            } else {

                    std::ostringstream oss ;
                    oss << "unregistered frequency : " << id ;
                    QL_FAIL(oss.str()) ;

                }

    }


    QuantLib::Frequency frequencyFactory::operator()(const int & n) {


            switch(n) {


                    case 0 :


                        idObject = "Once" ;

                        break ;


                    case 1 :


                        idObject = "Annual" ;
                        
						break ;


                    case 2 :


                        idObject = "Semi-Annual" ;
                        
						break ;


                    case 4 :


                        idObject = "Quarterly" ;
                        
						break ;


                    case 12 :


                        idObject = "Monthly" ;
                        
						break ;


                }


            if (RegistryManager<QuantLib::Frequency, EnumTypeRegistry>::checkType(idObject)) { // already registered

                return * (static_cast<QuantLib::Frequency *>(this->getType(idObject))) ;

            } else {

                    QL_FAIL("unregistered type") ;

                }

    }

    void frequencyFactory::registerType(const std::string & i, void * type) {

            RegistryManager<QuantLib::Frequency, EnumTypeRegistry>::registerType(i, type) ;

        }

}

