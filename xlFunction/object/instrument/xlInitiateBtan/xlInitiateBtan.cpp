/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateBtan/xlInitiateBtan.hpp>

        /* enregistre un TIPS */
DLLEXPORT xloper * xlInitiateBtan (const char * objectID_,
                                   const double * issueDate_,
                                   const double * effectiveDate_,
                                   const double * firstCouponDate_,
                                   const double * lastCouponDate_,
                                   const double * maturityDate_,
                                   const double * couponRate_,
                                   xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateBtan")) ;

    try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::btanValueObject> myBondValueObject(
            new QuantLibAddin::ValueObjects::btanValueObject(objectID_,
                                                             true)) ;

                // instanciation de l'instrument
            boost::shared_ptr<QuantLibAddin::btanObject> myBondObject(
                new QuantLibAddin::btanObject(myBondValueObject,
                                              QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
                                              QuantLib::Date(static_cast<QuantLib::BigInteger>(* effectiveDate_)),
                                              QuantLib::Date(static_cast<QuantLib::BigInteger>(* firstCouponDate_)),
                                              QuantLib::Date(static_cast<QuantLib::BigInteger>(* lastCouponDate_)),
                                              QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                                              QuantLib::Rate(* couponRate_),
                                              true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    myBondObject, 
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
