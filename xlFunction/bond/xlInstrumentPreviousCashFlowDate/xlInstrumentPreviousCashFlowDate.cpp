/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/08/10
 *  Copyright 2009. All /rights r/eserved.
 *
 */

#include <xlFunction/bond/xlInstrumentPreviousCashFlowDate/xlInstrumentPreviousCashFlowDate.hpp>

        /* fonction de récupération de la date de cashflow suivante */
DLLEXPORT xloper * xlInstrumentPreviousCashFlowDate (const char * objectID_,
                                                     xloper * testDate_,
                                                     xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInstrumentPreviousCashFlowDate")) ;

        try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(testDate_, "test Date") ;

            ObjectHandler::ConvertOper myOper(* testDate_) ;

            QuantLib::Date testDate(myOper.missing() ?
                QuantLib::Date() :
                QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper))) ;


                // on récupère l'instrument
            OH_GET_UNDERLYING(myBond,
                              objectID_, 
                              QuantLibAddin::Bond,
                              QuantLib::Bond)

            double returnDate = QuantLib::BondFunctions::previousCashFlowDate(
                myBond,
                testDate).serialNumber() ;

            static OPER returnOper ;

            ObjectHandler::scalarToOper(returnDate, returnOper) ;

            return & returnOper ;


        } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(e.what(), returnOper) ;

                return & returnOper ;


            }

    } ;

