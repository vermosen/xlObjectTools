/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentFlowCount/xlInstrumentFlowCount.hpp>

        /* Fonction de calcul du nombre de flux restant */
DLLEXPORT xloper * xlInstrumentFlowCount (const char * instrumentId_,
                                          xloper * settlementDate_,
                                          xloper * trigger_) {

         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInstrumentFlowCount")) ;

         try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    /* recherche de code erreur */
            ObjectHandler::validateRange(trigger_, "trigger") ;
            ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

                /* on récupère l'instrument */
            OH_GET_UNDERLYING(myBond, 
                              instrumentId_, 
                              QuantLibAddin::Bond,
                              QuantLib::Bond)

                /* les XLOPER des date */
            ObjectHandler::ConvertOper myOper(* settlementDate_) ;

            QuantLib::Date settlementDate(
                    myOper.missing() ? 
                    QuantLib::Date() : 
                    QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper))) ;

            QuantLib::Natural returnValue = myBond.flowCount(settlementDate) ;

            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(static_cast<double>(returnValue), returnOper) ;

            return & returnOper ;

        } catch (std::exception & e) {

            #ifdef _DEBUG

				OutputDebugString(e.what()) ;

            #endif

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
            static XLOPER returnOper ;
            returnOper.xltype = xltypeErr ;
            returnOper.val.err = xlerrValue ;

            return & returnOper ;


        }


    } ;