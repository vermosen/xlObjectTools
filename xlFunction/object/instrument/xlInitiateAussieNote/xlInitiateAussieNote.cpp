/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateAussieNote/xlInitiateAussieNote.hpp>

        /* enregistre un TIPS */
DLLEXPORT xloper * xlInitiateAussieNote (const char * objectID_,
                                         const double * issueDate_,
                                         xloper * effectiveDate_,
                                         xloper * firstCouponDate_,
                                         xloper * lastCouponDate_,
                                         const double * maturityDate_,
                                         const double * couponRate_,
                                         xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateAussieNote")) ;

    try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(effectiveDate_, "effective Date") ;

            ObjectHandler::validateRange(firstCouponDate_, "first Coupon Date") ;

            ObjectHandler::validateRange(lastCouponDate_, "last Coupon Date") ;


            ObjectHandler::ConvertOper myOper1(* effectiveDate_) ;

            ObjectHandler::ConvertOper myOper2(* firstCouponDate_) ;

            ObjectHandler::ConvertOper myOper3(* lastCouponDate_) ;


            QuantLib::Date issueDate(static_cast<QuantLib::BigInteger>(* issueDate_)) ;

            QuantLib::Date effectiveDate(myOper1.missing() ? 
                issueDate : 
                static_cast<QuantLib::Date>(myOper1)) ;

            QuantLib::Date firstCouponDate(myOper2.missing() ? 
                QuantLib::Date() : 
                static_cast<QuantLib::Date>(myOper2)) ;

            QuantLib::Date lastCouponDate(myOper3.missing() ? 
                QuantLib::Date() : 
                static_cast<QuantLib::Date>(myOper3)) ;

            QuantLib::Date maturityDate(static_cast<QuantLib::BigInteger>(* maturityDate_)) ;
                                         

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::australianTreasuryNoteValueObject> myBondValueObject(
				new QuantLibAddin::ValueObjects::australianTreasuryNoteValueObject(objectID_,
                                                                       true)) ;

                // instanciation de l'instrument
            boost::shared_ptr<QuantLibAddin::australianTreasuryNoteObject> myBondObject(
				new QuantLibAddin::australianTreasuryNoteObject(myBondValueObject,
                                                    issueDate,
                                                    effectiveDate,
                                                    firstCouponDate,
                                                    lastCouponDate,
                                                    maturityDate,
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
