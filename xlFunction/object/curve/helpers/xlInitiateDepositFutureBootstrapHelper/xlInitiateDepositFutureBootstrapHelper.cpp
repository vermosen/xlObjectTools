/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateDepositFutureBootstrapHelper/xlInitiateDepositFutureBootstrapHelper.hpp>


        /* enregistre un helper pour un depôt */
DLLEXPORT xloper * xlInitiateDepositFutureBootstrapHelper (const char * objectId_,
														   const char * immCode_,
														   const char * iborIndex_,
                                                           const double * futureQuote_,
														   const xloper * convexityAdjustmentQuote_,
														   const xloper * meanRevertingQuote_,
                                                           const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateDepositFutureBootstrapHelper")) ;

        try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

        ObjectHandler::validateRange(										// validate ranges
			trigger_, "trigger") ;					
		ObjectHandler::validateRange(
			convexityAdjustmentQuote_, "convexity Adjustment Quote") ;
		ObjectHandler::validateRange(
			meanRevertingQuote_, "mean Reverting Handle") ;

					
		ObjectHandler::ConvertOper myOper1(* convexityAdjustmentQuote_),	// xlOper conversion
									myOper2(* meanRevertingQuote_) ;

        boost::shared_ptr<QuantLib::Quote> convexityAdjustmentQuote(
            new QuantLib::SimpleQuote(myOper1.missing() ? 
				0.0 : static_cast<double>(myOper1))) ;

        boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > convexityAdjustmentQuoteHandle(
            new QuantLib::Handle<QuantLib::Quote>(convexityAdjustmentQuote)) ;

        boost::shared_ptr<QuantLib::Quote> meanRevertingQuote(
            new QuantLib::SimpleQuote(myOper2.missing() ? 
				0.0 : static_cast<double>(myOper2))) ;

        boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > meanRevertingQuoteHandle(
            new QuantLib::Handle<QuantLib::Quote>(convexityAdjustmentQuote)) ;

		OH_GET_REFERENCE(iborIndexPtr,										// retrieve the LIBOR rate
							iborIndex_, 
							QuantLibAddin::iborIndexObject, 
							QuantLib::IborIndex)

        boost::shared_ptr<QuantLib::Quote> myQuote(							// build the quote
            new QuantLib::SimpleQuote(* futureQuote_)) ;

        boost::shared_ptr<QuantLib::Handle<QuantLib::Quote> > myQuoteHandle(
            new QuantLib::Handle<QuantLib::Quote>(myQuote)) ;
				
		// build the value object
		boost::shared_ptr<QuantLibAddin::ValueObjects::depositFutureBootstrapHelperValueObject> myDepositFutureValueObject(
			new QuantLibAddin::ValueObjects::depositFutureBootstrapHelperValueObject(
			objectId_, true));
                
		// create the object
        boost::shared_ptr<QuantLibAddin::depositFutureBootstrapHelperObject> myDepositFutureObject(
            new QuantLibAddin::depositFutureBootstrapHelperObject(
				myDepositFutureValueObject,
                immCode_,
				QuantLib::Settings::instance().evaluationDate().value(),
				* myQuoteHandle,
                iborIndexPtr,
				* convexityAdjustmentQuoteHandle,
				* meanRevertingQuoteHandle,
                true)) ;

        std::string returnValue =											// object storage
            ObjectHandler::RepositoryXL::instance().storeObject(
				objectId_,
                myDepositFutureObject,
                true) ;														// overwrite the existing object

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