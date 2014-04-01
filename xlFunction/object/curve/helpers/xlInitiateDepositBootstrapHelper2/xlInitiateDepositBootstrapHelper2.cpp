/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateDepositBootstrapHelper2/xlInitiateDepositBootstrapHelper2.hpp>

        /* enregistre un helper pour un depôt */
DLLEXPORT xloper * xlInitiateDepositBootstrapHelper2 (const char * objectId_,
                                                      const char * tenor_,
													  const xloper * calendar_,
													  const xloper * settlementDays_,
                                                      const double * depositYield_,
													  const xloper * annualBasis_,
                                                      const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateDepositBootstrapHelper2")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_,        "trigger") ;
				ObjectHandler::validateRange(calendar_,       "calendar") ;
				ObjectHandler::validateRange(settlementDays_, "settlement days") ;
				ObjectHandler::validateRange(annualBasis_,    "annual basis") ;

					/* gestion des oper */
				ObjectHandler::ConvertOper myOper1(* calendar_),
										   myOper2(* settlementDays_),
										   myOper3(* annualBasis_) ;


                    // creation du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject> depositValueObject(
                    new QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject(objectId_,
                                                                                       true)) ;
				    

                QuantLib::Natural settlementDays(
                    myOper2.missing() ? 
                    2 :  static_cast<long>(myOper2)) ;

                QuantLib::Calendar calendar(
                    myOper1.missing() ? 
                    QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement) : 
                    ObjectHandler::calendarFactory()(static_cast<std::string>(myOper1))) ;

                QuantLib::Date valueDate(calendar.advance(QuantLib::Settings::instance().evaluationDate().value(), 
														  settlementDays, QuantLib::Days)) ;

				QuantLib::DayCounter annualBasis(
                    myOper3.missing() ? 
                    QuantLib::Actual360() :
                    ObjectHandler::daycountFactory()(static_cast<std::string>(myOper3))) ;

					// création du dépot
				boost::shared_ptr<QuantLib::deposit> myDepositPtr (
					new QuantLib::deposit(valueDate,
												  calendar.advance(valueDate, ObjectHandler::periodFactory()(tenor_)),
												  calendar,
												  settlementDays,
												  QuantLib::Unadjusted)) ;

					// creation de la quote
				boost::shared_ptr<QuantLib::Quote> myQuote(
                    new QuantLib::SimpleQuote(myDepositPtr->cleanPrice(* depositYield_,
																	   annualBasis,
																	   QuantLib::Simple,
																	   QuantLib::Once,
																	   QuantLib::Unadjusted,
																	   valueDate))) ;

                    // création du handler
                QuantLib::Handle<QuantLib::Quote> quoteHandler(myQuote) ;

                    // creation du helper
                boost::shared_ptr<QuantLibAddin::depositBootstrapHelperObject> depositBootstrapObject(
                    new QuantLibAddin::depositBootstrapHelperObject(depositValueObject,
                                                                    myDepositPtr,
                                                                    quoteHandler,
                                                                    true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        depositBootstrapObject,
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