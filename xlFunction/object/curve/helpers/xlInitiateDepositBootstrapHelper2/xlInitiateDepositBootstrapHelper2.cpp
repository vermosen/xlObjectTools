/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateDepositBootstrapHelper2/xlInitiateDepositBootstrapHelper2.hpp>

/* register a deposit for curve fitting */
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

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

                // range validation
                ObjectHandler::validateRange(trigger_       , "trigger"        );
				ObjectHandler::validateRange(calendar_      , "calendar"       );
				ObjectHandler::validateRange(settlementDays_, "settlement days");
				ObjectHandler::validateRange(annualBasis_   , "annual basis"   );

				// OPER management
				ObjectHandler::ConvertOper myOper1(* calendar_      ),
										   myOper2(* settlementDays_),
										   myOper3(* annualBasis_   );

                // creates a value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject> depositValueObject(
                    new QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject(
						objectId_, true)) ;
				    
				// quantlib objects
                QuantLib::Natural settlementDays(
                    myOper2.missing() ? 
                    2 :  static_cast<long>(myOper2)) ;

                QuantLib::Calendar calendar(
                    myOper1.missing() ? 
                    QuantLib::UnitedStates(
						QuantLib::UnitedStates::Settlement) : 
                    ObjectHandler::calendarFactory()(
						static_cast<std::string>(myOper1)));

                QuantLib::Date valueDate(
					calendar.advance(
						QuantLib::Settings::instance().evaluationDate().value(), 
						settlementDays, QuantLib::Days)) ;

				QuantLib::DayCounter annualBasis(
                    myOper3.missing() ? 
                    QuantLib::Actual360() :
                    ObjectHandler::daycountFactory()(
						static_cast<std::string>(myOper3)));

				// creates the deposit
				boost::shared_ptr<QuantLib::deposit> myDepositPtr (
					new QuantLib::deposit(
						valueDate,
						calendar.advance(valueDate, ObjectHandler::periodFactory()(tenor_)),
						calendar,
						 settlementDays,
						QuantLib::Unadjusted));

                    // creates the helper
                boost::shared_ptr<QuantLibAddin::depositBootstrapHelperObject> depositBootstrapObject(
                    new QuantLibAddin::depositBootstrapHelperObject(
						depositValueObject,
                        myDepositPtr,
						QuantLib::Handle<QuantLib::Quote>(
							boost::shared_ptr<QuantLib::Quote>(
								new QuantLib::SimpleQuote(
									myDepositPtr->cleanPrice(
										*depositYield_,
										annualBasis,
										QuantLib::Simple,
										QuantLib::Once,
										QuantLib::Unadjusted,
										valueDate)))),
                        true));

                    // storage of the object
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(
						objectId_,
                        depositBootstrapObject,
                        true);

                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(returnValue, returnOper) ;
                return & returnOper ;

            } catch (std::exception & e) 
			{
                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                    static XLOPER returnOper ;
                    ObjectHandler::scalarToOper(e.what(), returnOper) ;
                    return & returnOper ;
            }
    };