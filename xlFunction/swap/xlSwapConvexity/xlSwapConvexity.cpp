/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapConvexity/xlSwapConvexity.hpp>

        /* Fonction de calcul de l'accrued des instruments */
DLLEXPORT xloper * xlSwapConvexity (const char * instrumentId_,
                                    const char * curveId_,
                                    xloper * trigger_) {


         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlSwapConvexity")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;
                QuantLib::Real returnValue ;

                OH_GET_REFERENCE(instrumentPtr, 
								 instrumentId_, 
								 QuantLibAddin::interestRateSwapObject, 
								 QuantLib::vanillaSwap2)

				//returnValue = instrumentPtr->dv01();
				returnValue = 0;

                static XLOPER returnOper ;
                ObjectHandler::scalarToOper(returnValue, returnOper) ;
                return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
                returnOper.xltype = xltypeErr ;
                returnOper.val.err = xlerrValue ;

                return & returnOper ;

        }

} ;