/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateDeposit/xlInitiateDeposit.hpp>

        /* enregistre un depôt */
DLLEXPORT xloper * xlInitiateDepositFuture (const char * objectID_,
                                            const double * referenceDate_,
                                            const char * maturityCode_,
                                            const xloper * calendar_,
                                            const xloper * settlementDays_,
                                            const xloper * paymentConvention_,
                                            const xloper * endOfmonth_,
                                            const xloper * trigger_) {

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateDepositFuture")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(calendar_, "calendar") ;

                ObjectHandler::validateRange(settlementDays_, "settlement Days") ;

                ObjectHandler::validateRange(paymentConvention_, "payment Convention") ;

                ObjectHandler::validateRange(endOfmonth_, "end Of Month") ;

                    // les XLOPER
                ObjectHandler::ConvertOper myOper1(* calendar_),
                                           myOper2(* settlementDays_),
                                           myOper3(* paymentConvention_),
                                           myOper4(* endOfmonth_) ;

                QuantLib::Calendar calendar(
                    myOper1.missing() ? 
                    QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement) : 
                    ObjectHandler::calendarFactory()(static_cast<std::string>(myOper1))) ;

                //QuantLib::Date referenceDate(
                //    myOper1.missing() ? 
                //    calendar.advance(QuantLib::Date(), settlementDays, QuantLib::Days) : 
                //    static_cast<QuantLib::Date>(myOper1)) ;

                //QuantLib::BusinessDayConvention paymentConvention(
                //    myOper4.missing() ? 
                //    QuantLib::Following :
                //    ObjectHandler::businessDayConventionFactory()(static_cast<std::string>(myOper4))) ;

                //bool endOfMonth(
                //    myOper5.missing() ? 
                //    true :
                //    static_cast<bool>(myOper5)) ;

                //    // Construction du value object
                //boost::shared_ptr<QuantLibAddin::ValueObjects::depositValueObject> myDepositValueObject(
                //    new QuantLibAddin::ValueObjects::depositValueObject(objectID_,
                //                                                        true)) ;


                //    // instanciation de l'instrument
                //boost::shared_ptr<QuantLibAddin::depositObject> myDepositObject(
                //    new QuantLibAddin::depositObject(myDepositValueObject,
                //                                     startDate,
                //                                     QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                //                                     calendar,
                //                                     settlementDays,
                //                                     paymentConvention,
                //                                     endOfMonth,
                //                                     true)) ;

                //    // stockage de l'objet
                //std::string returnValue =
                //    ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                //                                                        myDepositObject, 
                //                                                        true) ; // on force la réécriture

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(0.0, returnOper) ;

                return & returnOper ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    static XLOPER returnOper ;

                    ObjectHandler::scalarToOper(e.what(), returnOper) ;

                    return & returnOper ;


            }


    } ;