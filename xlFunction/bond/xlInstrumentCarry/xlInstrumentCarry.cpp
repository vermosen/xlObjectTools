/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentCarry/xlInstrumentCarry.hpp>
#include <ql/interestrate.hpp>

    /* Fonction de calcul du carry d'un bond */
DLLEXPORT xloper * xlInstrumentCarry (const char * instrumentId_,
                                      const double * startAccruedDate_,
                                      const double * endAccruedDate_,
                                      const double * instrumentYield_,
                                      const char * conventionId_,
                                      xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentCarry")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

        double returnValue ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

            // on récupère la convention
        OH_GET_REFERENCE(conventionPtr, 
                         conventionId_, 
                         QuantLibAddin::interestRateConventionObject,
						 QuantLib::InterestRate)

            // on récupère l'instrument
        OH_GET_UNDERLYING(myBond, 
                          instrumentId_, 
                          QuantLibAddin::Bond,
                          QuantLib::Bond)

        returnValue = myBond.cleanPrice(* instrumentYield_,
                                        conventionPtr->dayCounter(),
                                        conventionPtr->compounding(),
                                        conventionPtr->frequency(),
                                        conventionPtr->businessDayConvention(),
                                        myBond.settlementDate(
                                            QuantLib::Date(static_cast<QuantLib::BigInteger>(* endAccruedDate_)))) ;

        returnValue -= myBond.cleanPrice(* instrumentYield_,
                                         conventionPtr->dayCounter(),
                                         conventionPtr->compounding(),
                                         conventionPtr->frequency(),
                                         conventionPtr->businessDayConvention(),
                                         myBond.settlementDate(
                                            QuantLib::Date(static_cast<QuantLib::BigInteger>(* startAccruedDate_)))) ;

            // variable de retour
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

}