/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateOvernightIndexedBootstrapHelper/xlInitiateOvernightIndexedBootstrapHelper.hpp>

        /* enregistre un helper pour un swap OIS */
DLLEXPORT xloper * xlInitiateOvernightIndexedBootstrapHelper (const char * objectId_,
                                                              const char * indexId_,
															  const double * maturityDate_,
                                                              const double * swapQuote_,
                                                              const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateOvernightIndexedBootstrapHelper")) ;

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

        ObjectHandler::validateRange(trigger_, "trigger");		// validate range

        OH_GET_REFERENCE(										// get a reference
			indexPtr,
            indexId_,
            QuantLibAddin::overnightIndexObject,
            QuantLib::OvernightIndex)

        QuantLib::Handle<QuantLib::Quote> quoteHandler(			// handle creation
			boost::shared_ptr<QuantLib::Quote>(
				new QuantLib::SimpleQuote(*swapQuote_)));


        // value object creation
        boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject> swapOISValueObject(
            new QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject(objectId_,
                                                                                true));

        // helper creation
        boost::shared_ptr<QuantLibAddin::overnightIndexedSwapBootstrapHelperObject> swapOISBootstrapObject(
            new QuantLibAddin::overnightIndexedSwapBootstrapHelperObject(swapOISValueObject,
                                                                            QuantLib::Settings::instance().evaluationDate().value(),
                                                                            QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
																			quoteHandler,
																			indexPtr,
                                                                            true));

        // objet storage, enforce rewriting
        std::string returnValue =
            ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                swapOISBootstrapObject,
                                                                true);

        static XLOPER returnOper;
        ObjectHandler::scalarToOper(returnValue, returnOper);
        return & returnOper;

    } catch (std::exception & e) {

        ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
        static XLOPER returnOper;
        ObjectHandler::scalarToOper(e.what(), returnOper);
        return & returnOper;

    }

} ;