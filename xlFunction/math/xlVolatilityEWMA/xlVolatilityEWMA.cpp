/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/math/xlVolatilityEWMA/xlVolatilityEWMA.hpp>

        /* fonction de calcul de la volatilité EWMA d'une série */
DLLEXPORT xloper * xlVolatilityEWMA(const char * timeSeriesId_,
                                    const double * decay_,
								    const double * valueDate_,
                                    xloper * trigger_) {

boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlVolatilityEWMA")) ;

     try {

			QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

				// trigger pour provoquer le recalcul
			ObjectHandler::validateRange(trigger_, "trigger") ;

				/* on récupère la série temporelle */
			OH_GET_REFERENCE(TimeSeriesPtr,
							 timeSeriesId_,
							 QuantLibAddin::TimeSeriesObject<double>,
							 QuantLib::TimeSeries<double>)

			static XLOPER returnOper ;

			ObjectHandler::scalarToOper(
				pow(covarianceEWMA(* TimeSeriesPtr,
								   * TimeSeriesPtr,
								   QuantLib::Date(static_cast<QuantLib::BigInteger>(* valueDate_)), 
								   decay_)

					- pow(meanEWMA(* TimeSeriesPtr, 
								   QuantLib::Date(static_cast<QuantLib::BigInteger>(* valueDate_)), 
								   decay_), 2) + QL_EPSILON, 0.5), returnOper) ;


			return & returnOper ;

		} catch (std::exception & e) {


				ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

				static XLOPER returnOper ;

				ObjectHandler::scalarToOper(e.what(), returnOper) ;

				return & returnOper ;


			}

} ;