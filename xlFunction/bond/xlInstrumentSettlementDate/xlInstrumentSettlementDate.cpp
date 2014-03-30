/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentSettlementDate/xlInstrumentSettlementDate.hpp>

    /* Fonction de calcul de la date de règlement des instruments */
DLLEXPORT xloper * xlInstrumentSettlementDate (const char * instrumentId_,
                                               xloper * evaluationDate_,
                                               xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentSettlementDate")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // contrôle des OPER
        ObjectHandler::validateRange(trigger_, "trigger") ;

        ObjectHandler::validateRange(evaluationDate_, "evaluation Date") ;

            // on récupère l'instrument
        OH_GET_UNDERLYING(myBond, 
                          instrumentId_, 
                          QuantLibAddin::Bond, 
                          QuantLib::Bond)

            // on récupère la date
        ObjectHandler::ConvertOper myOper(* evaluationDate_) ;

            // contrôle sur l'argument
        QuantLib::Date evaluationDate(
            myOper.missing() ? 
            QuantLib::Date() : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper))) ;


        static XLOPER returnOper ;

        ObjectHandler::scalarToOper(static_cast<double>(myBond.settlementDate(evaluationDate).serialNumber()), returnOper) ;

        return & returnOper ;


    } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                returnOper.xltype = xltypeErr ;

                returnOper.val.err = xlerrValue ;

                return & returnOper ;


        }

} ;