/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentYield/xlInstrumentYield.hpp>

        /* Fonction de calcul du yield d'un instrument */
DLLEXPORT xloper * xlInstrumentYield (const char * instrumentId_,
                                      const double * price_,
                                      xloper * settlementDate_,
                                      const char * conventionId_,
                                      xloper * trigger_) {


     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentYield")) ;

     try {


        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;


            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

        ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

        ObjectHandler::ConvertOper myOper(* settlementDate_) ;


            // on récupère l'instrument pointé
        OH_GET_UNDERLYING(myBond, 
                          instrumentId_, 
                          QuantLibAddin::Bond,
                          QuantLib::Bond)


            // on récupère la convention
        OH_GET_REFERENCE(conventionPtr, 
                         conventionId_, 
                         QuantLibAddin::interestRateConventionObject,
                         QuantLib::InterestRate)


        QuantLib::Date settlementDate(
            myOper.missing() ?
            QuantLib::Date() :
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper))) ;


        double returnValue = myBond.yield(* price_,
                                          conventionPtr->dayCounter(),
                                          conventionPtr->compounding(),
                                          conventionPtr->frequency(),
                                          conventionPtr->businessDayConvention(),
                                          settlementDate,
                                          1e-12, 200) ;


        static XLOPER returnOper ;

        ObjectHandler::scalarToOper(returnValue, returnOper) ;

        return & returnOper ;


    } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                returnOper.xltype = xltypeErr ;

                returnOper.val.err = xlerrValue ;

                return & returnOper ;


        }


} ;
