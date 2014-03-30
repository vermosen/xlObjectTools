/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentDuration/xlInstrumentDuration.hpp>

    /* Fonction de calcul des prix théoriques des instruments */
DLLEXPORT xloper * xlInstrumentDuration (const char * instrumentId_,
                                         xloper * npvDate_,
                                         xloper * settlementDate_,
                                         const double * instrumentCleanPrice_,
                                         xloper * durationType_,
                                         const char * conventionId_,
                                         xloper * trigger_) {


     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentDuration")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;
        QuantLib::Real returnValue ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;
        ObjectHandler::validateRange(npvDate_, "npv Date") ;
        ObjectHandler::validateRange(settlementDate_, "settlement Date") ;
        ObjectHandler::validateRange(durationType_, "duration Type") ;

            // on récupère la convention de taux
        OH_GET_REFERENCE(conventionPtr, 
                         conventionId_, 
                         QuantLibAddin::interestRateConventionObject,
                         QuantLib::interestRateConvention)

            // on récupère l'instrument
        OH_GET_UNDERLYING(myBond, 
                          instrumentId_, 
                          QuantLibAddin::Bond,
                          QuantLib::Bond)

            // les XLOPER des date
        ObjectHandler::ConvertOper myOper1(* npvDate_),
                                   myOper2(* settlementDate_),
                                   myOper3(* durationType_) ;

        QuantLib::Date npvDate(
            myOper1.missing() ? 
            QuantLib::Date() : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

        QuantLib::Date settlementDate(
            myOper2.missing() ? 
            myBond.settlementDate(npvDate) : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper2))) ;

        QuantLib::Duration::Type durationType(
            myOper1.missing() ? 
            QuantLib::Duration::Modified : 
            ObjectHandler::durationFactory()(static_cast<std::string>(myOper3))) ;

        QuantLib::Rate yield = QuantLib::BondFunctions::yield(myBond,
                                                              * instrumentCleanPrice_,
                                                              conventionPtr->daycounter(), 
                                                              conventionPtr->compounding(),
                                                              conventionPtr->frequency(),
                                                              conventionPtr->businessDayConvention(),
                                                              settlementDate,
                                                              1e-8, 100) ;

        returnValue = QuantLib::BondFunctions::duration(myBond,
                                                        yield,
                                                        conventionPtr->daycounter(),
                                                        conventionPtr->compounding(),
                                                        conventionPtr->frequency(),
                                                        conventionPtr->businessDayConvention(),
                                                        durationType,
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

} ;