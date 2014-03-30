/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateDeposit/xlInitiateDeposit.hpp>

        /* enregistre un depôt */
DLLEXPORT xloper * xlInitiateDeposit (const char * objectID_,
                                      const xloper * startDate_,
                                      const double * maturityDate_,
                                      const xloper * calendar_,
                                      const xloper * settlementDays_,
                                      const xloper * paymentConvention_,
                                      const xloper * endOfmonth_,
                                      const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateDeposit")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(startDate_, "start Date") ;

                ObjectHandler::validateRange(calendar_, "calendar") ;

                ObjectHandler::validateRange(settlementDays_, "settlement Days") ;

                ObjectHandler::validateRange(paymentConvention_, "payment Convention") ;

                ObjectHandler::validateRange(endOfmonth_, "end Of Month") ;

                    // les XLOPER
                ObjectHandler::ConvertOper myOper1(* startDate_), 
                                           myOper2(* calendar_),
                                           myOper3(* settlementDays_),
                                           myOper4(* paymentConvention_),
                                           myOper5(* endOfmonth_) ;

                QuantLib::Natural settlementDays(
                    myOper3.missing() ? 
                    2 :  static_cast<long>(myOper3)) ;

                QuantLib::Calendar calendar(
                    myOper2.missing() ? 
                    QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement) : 
                    ObjectHandler::calendarFactory()(static_cast<std::string>(myOper2))) ;

                QuantLib::Date startDate(
                    myOper1.missing() ? 
                    calendar.advance(QuantLib::Settings::instance().evaluationDate().value(), 
									 settlementDays, QuantLib::Days) : 
                    static_cast<QuantLib::Date>(myOper1)) ;

                QuantLib::BusinessDayConvention paymentConvention(
                    myOper4.missing() ? 
                    QuantLib::Following :
                    ObjectHandler::businessDayConventionFactory()(static_cast<std::string>(myOper4))) ;

                bool endOfMonth(
                    myOper5.missing() ? 
                    true :
                    static_cast<bool>(myOper5)) ;

                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::depositValueObject> myDepositValueObject(
                    new QuantLibAddin::ValueObjects::depositValueObject(objectID_,
                                                                        true)) ;


                    // instanciation de l'instrument
                boost::shared_ptr<QuantLibAddin::depositObject> myDepositObject(
                    new QuantLibAddin::depositObject(myDepositValueObject,
                                                     startDate,
                                                     QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                                                     calendar,
                                                     settlementDays,
                                                     paymentConvention,
                                                     endOfMonth,
                                                     true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                        myDepositObject, 
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