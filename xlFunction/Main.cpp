/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "Main.hpp"

DLLEXPORT int xlAutoOpen() {

            // Instantiate the ObjectHandler Repository
        static ObjectHandler::RepositoryXL repositoryXL ;

            // Instantiate the Enumerated Type Registry
        static ObjectHandler::EnumTypeRegistry enumTypeRegistry ;

            // Instantiate the Enumerated Class Registry
        static ObjectHandler::EnumClassRegistry enumClassRegistry ;

            // Instantiate the Enumerated Pair Registry
        static ObjectHandler::EnumPairRegistry enumPairRegistry ;

            // Instantiate the Processor Factory
        static ObjectHandler::ProcessorFactory processorFactory ;

            // Instantiate the Serialization Factory
        static QuantLibAddin::serializationFactory serializationFactory ;

        static XLOPER xDll ;

        try {

                Excel(xlGetName, & xDll, 0);
                ObjectHandler::Configuration::instance().init() ;

                // factory registering
                registerCalendars() ;
                registerDayCounter() ;
                registerFrequency() ;
                registerCompounding() ;
                registerDuration() ;
                registerBusinessDayConvention() ;
                registerPeriod() ;
                registerCurrency() ;
                registerConstraint() ;
                registerBondSelectionRule() ;

                // Excel functions registering
                registerAll(xDll) ;
                Excel(xlFree, 0, 1, & xDll) ;
                return 1 ;


        } catch (const std::exception & e) {

                std::ostringstream err ;
                err << "Error loading xlObjectTools: " << e.what() ;
                Excel(xlcAlert, 0, 1, TempStrStl(err.str())) ;
                Excel(xlFree, 0, 1, & xDll) ;
                return 0 ;

        } catch (...) {

                Excel(xlFree, 0, 1, & xDll) ;
                return 0 ;

            }

    }

DLLEXPORT int xlAutoClose() {

        static XLOPER xDll;

        try {

                Excel(xlGetName, & xDll, 0) ;
                unregisterAll(xDll) ;
                Excel(xlFree, 0, 1, & xDll) ;
                return 1 ;

        } catch (const std::exception & e) {

                std::ostringstream err ;
                err << "Error unloading xlObjectTools: " << e.what() ;
                Excel(xlcAlert, 0, 1, TempStrStl(err.str())) ;
                Excel(xlFree, 0, 1, & xDll) ;
                return 0 ;

        } catch (...) {

                Excel(xlFree, 0, 1, & xDll) ;
                return 0 ;

            }

    }

DLLEXPORT void xlAutoFree(XLOPER * px) {

    freeOper(px) ;

}

