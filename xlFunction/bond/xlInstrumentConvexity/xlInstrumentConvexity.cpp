/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentConvexity/xlInstrumentConvexity.hpp>

    /* Fonction de calcul de le convexité des instruments */
DLLEXPORT xloper * xlInstrumentConvexity (const char * instrumentId_,
                                          const xloper * npvDate_,
                                          const xloper * settlementDate_,
                                          const double * instrumentCleanPrice_,
                                          const char * conventionId_,
                                          const xloper * trigger_) {

         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInstrumentConvexity")) ;

         try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // recherche de code erreur
            ObjectHandler::validateRange(trigger_, "trigger") ;
            ObjectHandler::validateRange(npvDate_, "npv Date") ;
            ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

                // on récupère la convention de taux
            OH_GET_REFERENCE(conventionPtr, 
                             conventionId_, 
                             QuantLibAddin::interestRateConventionObject, 
                             QuantLib::interestRateConvention)

                // on récupère l'instrument
            OH_GET_REFERENCE(bondPtr, 
                             instrumentId_, 
                             QuantLibAddin::Bond, 
                             QuantLib::Bond)

                // les XLOPER des date
            ObjectHandler::ConvertOper myOper1(* npvDate_), 
                                       myOper2(* settlementDate_) ;

            QuantLib::Date npvDate(
                myOper1.missing() ? 
                QuantLib::Date() : 
                QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

            QuantLib::Date settlementDate(
                myOper2.missing() ? 
                bondPtr->settlementDate(npvDate) : 
                QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper2))) ;

            QuantLib::Rate yield = bondPtr->yield(* instrumentCleanPrice_,
                                                  conventionPtr->daycounter(),
                                                  conventionPtr->compounding(),
                                                  conventionPtr->frequency(),
                                                  conventionPtr->businessDayConvention(),
                                                  settlementDate,
                                                  1e-8, 100) ;

            QuantLib::Real returnValue = QuantLib::BondFunctions::convexity(* bondPtr,
                                                                            yield,
                                                                            conventionPtr->daycounter(),
                                                                            conventionPtr->compounding(),
                                                                            conventionPtr->frequency(),
                                                                            conventionPtr->businessDayConvention(),
                                                                            settlementDate) ;

            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(returnValue, returnOper) ;
            return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(e.what(), returnOper) ;
                return & returnOper ;

        }


    }