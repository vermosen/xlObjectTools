/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/addin/xlPricingDate/xlPricingDate.hpp>

        /* fonction de récupération la date de pricing */
DLLEXPORT double xlPricingDate (xloper * date_,
                                xloper * trigger_) {

         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlPricingDate"));

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

                ObjectHandler::validateRange(date_, "date");			// validate ranges
				ObjectHandler::validateRange(trigger_, "trigger");

                ObjectHandler::ConvertOper myOper(* date_);				// convert xlOpers

				(!myOper.missing() ?									

				QuantLib::Settings::instance().evaluationDate() =
					QuantLib::Date(static_cast<long>(myOper)) :

				QuantLib::Settings::instance().evaluationDate() =		// default on today
					QuantLib::Date().todaysDate());

                return QuantLib::Settings::instance().evaluationDate().value().serialNumber();

            } catch (std::exception & e) {

                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall);
					return 0.0;

            }

    }