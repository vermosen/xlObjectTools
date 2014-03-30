/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentAccruedAmount/xlInstrumentAccruedAmount.hpp>

        /* Fonction de calcul de l'accrued des instruments */
DLLEXPORT xloper * xlInstrumentAccruedAmount (const char * instrumentId_,
                                              xloper * settlementDate_,
                                              xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentAccruedAmount")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

            // on récupère l'instrument
        OH_GET_UNDERLYING(myBond, 
                          instrumentId_, 
                          QuantLibAddin::Bond, 
                          QuantLib::Bond)

            // le XLOPER de la date
        ObjectHandler::ConvertOper myOper(* settlementDate_) ;

        QuantLib::Date settlementDate(
            myOper.missing() ? 
            myBond.settlementDate(QuantLib::Date()) : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper))) ;

            // la date de retour
        QuantLib::Real returnValue = myBond.accruedAmount(settlementDate) ;
        static XLOPER returnOper ;
        ObjectHandler::scalarToOper(returnValue, returnOper) ;
        return & returnOper ;

    } catch (std::exception & e) {

            #ifdef _DEBUG

                {

                        OutputDebugString("erreur dans l'appel de la fonction xlInstrumentAccruedAmount :") ;
                        OutputDebugString(e.what()) ;

                    }

            #endif

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
            static XLOPER returnOper ;
            returnOper.xltype = xltypeErr ;
            returnOper.val.err = xlerrValue ;
            return & returnOper ;

    }

} ;