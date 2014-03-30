/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlInitiateTreasuryBill.hpp"

        /* enregistre un bill */
DLLEXPORT char * xlInitiateTreasuryBill (const char * objectID_,
                                         const double * issueDate_,
                                         const double * maturityDate_,
                                         xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiatetreasuryBill")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // initialisation de la session
        ObjectHandler::validateRange(trigger_, "trigger") ;

            // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::treasuryBillValueObject> myBillValueObject(
        new QuantLibAddin::ValueObjects::treasuryBillValueObject(objectID_,
                                                          true)) ;

            // instanciation de l'instrument
        boost::shared_ptr<QuantLibAddin::treasuryBillObject> myBillObject(
            new QuantLibAddin::treasuryBillObject(myBillValueObject,
                QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
                QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                true)) ;

        // stockage de l'objet
        std::string returnValue =
            ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                myBillObject, 
                                                                true) ; // on force la réécriture

        static char ret[XL_MAX_STR_LEN] ;

        ObjectHandler::stringToChar(returnValue, ret) ;

        return ret ;

    } catch (std::exception & e) {

            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

            ObjectHandler::stringToChar(e.what(), ret) ;

            return ret ;

    }

} ;
