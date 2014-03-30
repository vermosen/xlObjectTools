/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateAussieBill/xlInitiateAussieBill.hpp>

        /* enregistre un Bill australien */
DLLEXPORT xloper * xlInitiateAussieBill (const char * objectID_,
                                         const double * issueDate_,
                                         const double * maturityDate_,
                                         const xloper * settlementDays_,
                                         const xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateAussieBill")) ;

    try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(settlementDays_, "settlement Days") ;

                // récupération du oper
            ObjectHandler::ConvertOper myOper(* settlementDays_) ;

            QuantLib::Natural settlementDays(
                myOper.missing() ? 3 : 
                static_cast<QuantLib::BigInteger>(myOper)) ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::aussieBillValueObject> myBondValueObject(
            new QuantLibAddin::ValueObjects::aussieBillValueObject(objectID_,
                                                                   true)) ;

                // instanciation de l'instrument
            boost::shared_ptr<QuantLibAddin::aussieBillObject> myBillObject(
                new QuantLibAddin::aussieBillObject(myBondValueObject,
                                                    QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                                                    QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
                                                    settlementDays,
                                                    true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    myBillObject, 
                                                                    true) ; // on force la réécriture

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
