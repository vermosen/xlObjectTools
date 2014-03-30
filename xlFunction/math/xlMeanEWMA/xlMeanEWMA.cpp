/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "xlMeanEWMA.hpp"

DLLEXPORT xloper * xlMeanEWMA(const char * timeSeriesId_,
                              const double * decay_,
							  const double * valueDate_,
                              xloper * trigger_) {

boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlMeanEWMA")) ;

    try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* déclaration du trigger */
            ObjectHandler::validateRange(trigger_, "trigger") ;

                /* récupération des séries */
            OH_GET_REFERENCE(dataObject, 
							 timeSeriesId_, 
							 QuantLibAddin::TimeSeriesObject<double>, 
							 QuantLib::TimeSeries<double>)    
            
			static XLOPER returnOper ;

			ObjectHandler::scalarToOper(
				meanEWMA(* dataObject, 
						 QuantLib::Date(static_cast<QuantLib::BigInteger>(* valueDate_)), 
						 decay_), returnOper) ;

			return & returnOper ;

		} catch (std::exception & e) {


				ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

				static XLOPER returnOper ;

				ObjectHandler::scalarToOper(e.what(), returnOper) ;

				return & returnOper ;


			}

	} ;