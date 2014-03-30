/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateBtf/xlInitiateBtf.hpp>

        /* enregistre un Bill australien */
DLLEXPORT xloper * xlInitiateBtf (const char * objectID_,
                                  const double * issueDate_,
                                  const double * maturityDate_,
                                  xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateBtf")) ;

    try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::btfValueObject> myBondValueObject(
            new QuantLibAddin::ValueObjects::btfValueObject(objectID_,
                                                            true)) ;

                // instanciation de l'instrument
            boost::shared_ptr<QuantLibAddin::btfObject> myBillObject(
                new QuantLibAddin::btfObject(myBondValueObject,
                                             QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                                             QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
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
