/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateInterestRateSwapBootstrapHelper2/xlInitiateInterestRateSwapBootstrapHelper2.hpp>

        /* enregistre un helper pour un swap de taux */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper2 (const char * objectId_,
															   const char * tenor_,
															   const char * calendar_,
															   const xloper * settlementDays_,
                                                               const xloper * fixedFrequency_,
                                                               const xloper * fixedDayCount_,
															   const double * fixedRate_,
															   const xloper * floatFrequency_,
                                                               const xloper * floatDayCount_,
															   const char * floatIndex_,
															   const xloper * discountCurve_,
                                                               const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateInterestRateSwapBootstrapHelper2")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

				ObjectHandler::validateRange(settlementDays_, "settlement Days") ;

                ObjectHandler::validateRange(discountCurve_, "discount Curve") ;

				ObjectHandler::validateRange(fixedFrequency_, "fixed Frequency") ;

				ObjectHandler::validateRange(fixedDayCount_, "fixed DayCount") ;

				ObjectHandler::validateRange(floatFrequency_, "float Frequency") ;

				ObjectHandler::validateRange(floatDayCount_, "float DayCount") ;


                    /* récupération des oper */
				ObjectHandler::ConvertOper myOper1(* settlementDays_),
										   myOper2(* discountCurve_),
										   myOper3(* fixedFrequency_),
										   myOper4(* fixedDayCount_),
										   myOper5(* floatFrequency_),
										   myOper6(* floatDayCount_) ;


					/* calendrier */
				QuantLib::Calendar swapCalendar = 
					ObjectHandler::calendarFactory()(static_cast<std::string>(calendar_)) ;

				boost::shared_ptr<QuantLib::Frequency> fixedFrequency, floatFrequency ;

				boost::shared_ptr<QuantLib::DayCounter> fixedDayCount, floatDaycount ;

				boost::shared_ptr<QuantLib::Period> fwdPeriod ;

				QuantLib::Period swapPeriod = ObjectHandler::periodFactory()(tenor_) ;


					/* gestion des données statiques par défaut */
				if (swapCalendar.name() == "US government bond market" /*|| swapCalendar.name() == "USD" TODO pour LIBOR*/) {


						boost::shared_ptr<QuantLib::Frequency> tempFixedFrequency(
							new QuantLib::Frequency(myOper3.missing() ? QuantLib::Semiannual : 
							ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper3)))) ;

						boost::shared_ptr<QuantLib::Frequency> tempFloatFrequency(
							new QuantLib::Frequency(myOper5.missing() ? QuantLib::Quarterly : 
							ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper5)))) ;

						boost::shared_ptr<QuantLib::DayCounter> tempFixedDayCount(
							new QuantLib::DayCounter(myOper4.missing() ? QuantLib::Thirty360() : 
							ObjectHandler::daycountFactory()(static_cast<std::string>(myOper4)))) ;

						boost::shared_ptr<QuantLib::DayCounter> tempFloatDayCount(
							new QuantLib::DayCounter(myOper6.missing() ? QuantLib::Actual360() : 
							ObjectHandler::daycountFactory()(static_cast<std::string>(myOper6)))) ;

						boost::shared_ptr<QuantLib::Period> tempFwdPeriod(
							new QuantLib::Period(myOper1.missing() ? 2 : 
							static_cast<QuantLib::BigInteger>(myOper1), QuantLib::Days)) ;

						fixedFrequency = tempFixedFrequency ;

						floatFrequency = tempFloatFrequency ;

						fixedDayCount = tempFixedDayCount ;

						floatDaycount = tempFloatDayCount ;

						fwdPeriod = tempFwdPeriod ;

				
					}

				else if (swapCalendar.name() == "EUR" /*|| swapCalendar.name() == "USD" TODO pour LIBOR*/) {


						boost::shared_ptr<QuantLib::Frequency> tempFixedFrequency(
							new QuantLib::Frequency(myOper3.missing() ? QuantLib::Annual : 
							ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper3)))) ;

						boost::shared_ptr<QuantLib::Frequency> tempFloatFrequency(
							new QuantLib::Frequency(myOper5.missing() ? QuantLib::Quarterly : 
							ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper5)))) ;

						boost::shared_ptr<QuantLib::DayCounter> tempFixedDayCount(
							new QuantLib::DayCounter(myOper4.missing() ? QuantLib::Thirty360() : 
							ObjectHandler::daycountFactory()(static_cast<std::string>(myOper4)))) ;

						boost::shared_ptr<QuantLib::DayCounter> tempFloatDayCount(
							new QuantLib::DayCounter(myOper6.missing() ? QuantLib::Actual360() : 
							ObjectHandler::daycountFactory()(static_cast<std::string>(myOper6)))) ;

						boost::shared_ptr<QuantLib::Period> tempFwdPeriod(
							new QuantLib::Period(myOper1.missing() ? 2 : 
							static_cast<QuantLib::BigInteger>(myOper1), QuantLib::Days)) ;

						fixedFrequency = tempFixedFrequency ;

						floatFrequency = tempFloatFrequency ;

						fixedDayCount = tempFixedDayCount ;

						floatDaycount = tempFloatDayCount ;

						fwdPeriod = tempFwdPeriod ;


					}

				else {
				
				
						QL_FAIL("unmanaged calendar") ;
				
				
					}


                    /* gestion de la courbe de discounting */
				boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > discountHandle(
					new QuantLib::Handle<QuantLib::YieldTermStructure>) ;


				if (myOper2.missing()) {
					
						boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > tempHandle(
							new QuantLib::Handle<QuantLib::YieldTermStructure>()) ;

						discountHandle = tempHandle ;

					
					}

				else {
					
					
						OH_GET_REFERENCE(discountPtr,
										 static_cast<std::string>(myOper2),
										 QuantLibAddin::YieldTermStructure,
										 QuantLib::YieldTermStructure)

						boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > tempHandle(
							new QuantLib::Handle<QuantLib::YieldTermStructure>(discountPtr)) ;

						discountHandle = tempHandle ;
						
						
					}

					/* on récupère l'index libor */
				OH_GET_REFERENCE(iborIndexPtr, 
								 std::string(floatIndex_), 
								 QuantLibAddin::iborIndexObject,
								 QuantLib::IborIndex)  

					/* création du handle */
                QuantLib::Handle<QuantLib::Quote> myHandle(
                    boost::shared_ptr<QuantLib::Quote>(
                        new QuantLib::SimpleQuote(* fixedRate_))) ;


                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject2> mySwapHelperValueObject(
                    new QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject2(floatIndex_,
                                                                                                 true)) ;



                    // instanciation de l'instrument
                boost::shared_ptr<QuantLibAddin::interestRateSwapBootstrapHelperObject2> mySwapHelperObject(
                    new QuantLibAddin::interestRateSwapBootstrapHelperObject2(mySwapHelperValueObject,
                                                                              myHandle,
                                                                              swapPeriod,
																			  swapCalendar, 
																			  * fixedFrequency,
																			  QuantLib::ModifiedFollowing,
																			  * fixedDayCount,
																			  iborIndexPtr,
																			  QuantLib::Handle<QuantLib::Quote>(),
																			  * fwdPeriod,
																			  * discountHandle)) ;


                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        mySwapHelperObject,
                                                                        true) ;


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