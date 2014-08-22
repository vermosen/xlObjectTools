/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlFunction/object/yieldCurve/xlInitiateFittedBondDiscountCurve/xlInitiateFittedBondDiscountCurve.hpp"

// parametric fitted curve
DLLEXPORT char * xlInitiateFittedBondDiscountCurve (const char * objectID_           ,
													const xloper * evaluationDate_   ,
                                                    const xloper * settlementDate_   ,
                                                    const xloper * instruments_      ,
                                                    const xloper * quote_            ,
                                                    const char * calendarID_         ,
                                                    const char * fittingMethodID_    ,
													const xloper * bondSelectionRule_,
                                                    const xloper * trigger_) {

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateFittedBondDiscountCurve"));

        try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "");						// called by wizard ?

            ObjectHandler::validateRange(trigger_,           "trigger"            );	// validate range
			ObjectHandler::validateRange(settlementDate_,    "settlement Date"    );
            ObjectHandler::validateRange(instruments_,       "instruments"        );
            ObjectHandler::validateRange(quote_,             "quotes"             );
            ObjectHandler::validateRange(bondSelectionRule_, "bond selection rule");

            ObjectHandler::ConvertOper myOper1(* bondSelectionRule_);					// bond selection rule oper

            QuantLib::bondSelectionRule myRule =										// the rule
					(myOper1.missing() ?
                     QuantLib::activeRule() : 
                     ObjectHandler::bondSelectionRuleFactory()(
                         static_cast<std::string>(myOper1)));

            QuantLib::Calendar curveCalendar											// calendar
                = ObjectHandler::calendarFactory()(calendarID_);

            ObjectHandler::ConvertOper oper1(* evaluationDate_);						// evaluation date

            QuantLib::Date evaluationDate(oper1.missing() ? 
                QuantLib::Date() : 
                static_cast<QuantLib::Date>(oper1));

            std::vector<std::string> instruments =										// instrument ids
				ObjectHandler::operToVector<std::string>(
					* instruments_, "instruments");

            std::vector<QuantLib::Real> quote =											// quotes
				ObjectHandler::operToVector<double>(
					* quote_, "quote");

            std::vector<boost::shared_ptr<QuantLib::BondHelper> > instrumentsObject;	// helpers

            for (unsigned int i = 0 ; i < instruments.size() ; i++) {					// capture individual bonds

				try {

                    OH_GET_REFERENCE(instrumentPtr,										// get a reference
                                     instruments[i],
                                     QuantLibAddin::Bond, 
                                     QuantLib::Bond)

                    if (quote[i] != 0.0 && instrumentPtr->isTradable()) {				// valid quote ?

                            QuantLib::RelinkableHandle<QuantLib::Quote> quoteHandle;	// the handler
                            
							quoteHandle.linkTo(boost::shared_ptr<QuantLib::Quote>(		// link to the quote
								new QuantLib::SimpleQuote(quote[i])));

							boost::shared_ptr<QuantLib::BondHelper> noteHelper(			// the helper
								new QuantLib::BondHelper(quoteHandle, instrumentPtr));

                            instrumentsObject.push_back(noteHelper);					// helper storage

                        }

					} catch (...) {}													// nothing on exception

                }

            ObjectHandler::ConvertOper oper2(* settlementDate_);						// settlement date

            QuantLib::Date settlementDate(oper2.missing() ? 
                instrumentsObject[0]->bond()->settlementDate(evaluationDate) : 
                static_cast<QuantLib::Date>(oper2));

			OH_GET_OBJECT(fittingMethodTemp,											// fitting method selection
				fittingMethodID_,
				ObjectHandler::Object)

			std::string returnValue;

            if (fittingMethodTemp->properties()->className()								// svensson ?
				== "stochasticSvenssonFittingValueObject") {
                    
                    OH_GET_REFERENCE(fittingMethodPtr,
                                     fittingMethodID_,
                                     QuantLibAddin::stochasticFittingObject,
                                     QuantLib::stochasticFittingHelper)

                    // build the value object
                    boost::shared_ptr<QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject> curveValueObject(
                        new QuantLibAddin::ValueObjects::fittedBondDiscountCurveValueObject(
							objectID_,
                            settlementDate.serialNumber(),
                            true));

                    boost::shared_ptr<ObjectHandler::Object> myNSSCurve(				// instancing the curve
                        new QuantLibAddin::fittedBondDiscountCurveObject(
                            curveValueObject,
                            settlementDate,
                            myRule.select(instrumentsObject, settlementDate),
                            * fittingMethodPtr->fittingMethod(),
                            fittingMethodPtr->initialVector(),
                            fittingMethodPtr->randomMatrix(),
                            fittingMethodPtr->accuracy(),
                            fittingMethodPtr->maxEvaluationPercycle(),
                            fittingMethodPtr->cyclesPerThread(),
                            fittingMethodPtr->cycles(),
                            1.000,
                            true)) ;

					returnValue =											// the value to return
                        ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                            myNSSCurve,
                                                                            true) ;

                }

            static char ret[XL_MAX_STR_LEN] ;
			ObjectHandler::stringToChar(returnValue, ret);
            return ret;

        } catch (std::exception & e) {

				static char ret[XL_MAX_STR_LEN];
                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
                ObjectHandler::stringToChar(std::string(e.what()), ret);
                return ret;

            }

    } ;