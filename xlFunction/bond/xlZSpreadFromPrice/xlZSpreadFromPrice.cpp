/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlZSpreadFromPrice/xlZSpreadFromPrice.hpp>

        /*Fonction de calcul du z-spread conventionnel à partir du prix */
DLLEXPORT xloper * xlZSpreadFromPrice (const char * instrumentId_,
                                       const char * curveId_,
                                       const double * price_,
                                       xloper * conventionId_,
                                       xloper * settlementDate_,
                                       xloper * trigger_) {
    
		 boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
			new ObjectHandler::FunctionCall("xlZSpreadFromPrice")) ;

		 try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;
            ObjectHandler::validateRange(settlementDate_, "settlement Date") ;
            ObjectHandler::validateRange(conventionId_, "convention Id") ;

            ObjectHandler::ConvertOper myOper1(* settlementDate_) ;
            ObjectHandler::ConvertOper myOper2(* conventionId_) ;

                // on récupère la courbe des taux
            OH_GET_OBJECT(curveObjectPtr, curveId_, QuantLibAddin::YieldTermStructure)

                // conversions
            QuantLib::Handle<QuantLib::YieldTermStructure> curveHandler = 
                QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>() (curveObjectPtr) ;

            double returnValue = 0.0 ;

               // on récupère l'instrument pointé
            OH_GET_REFERENCE(instrumentPtr, 
                             instrumentId_, 
                             QuantLibAddin::Bond,
                             QuantLib::Bond)

            QuantLib::Date settlementDate(myOper1.missing() ?
                instrumentPtr->settlementDate(curveHandler->referenceDate()) :
                static_cast<QuantLib::Date>(myOper1)) ;

                if (myOper2.missing()) {
                    
                    
                        returnValue = QuantLib::BondFunctions::zSpread(* instrumentPtr,
			                                                           * price_,
														               * curveHandler,
                                                                       QuantLib::Actual365Fixed(),
														               QuantLib::Continuous,
                                                                       QuantLib::Annual,
                                                                       QuantLib::Unadjusted,
														               settlementDate,
														               1e-8, 100, 1.0) ; 
                    
                    }

                else {
                    
				        // on récupère la convention de marché
			        OH_GET_REFERENCE(conventionPtr, 
                                     static_cast<std::string>(myOper2), 
							         QuantLibAddin::interestRateConventionObject,
							         QuantLib::InterestRate)

                    returnValue = QuantLib::BondFunctions::zSpread(* instrumentPtr,
			                                                       * price_,
														           * curveHandler,
														           conventionPtr->dayCounter(),
														           conventionPtr->compounding(),
														           conventionPtr->frequency(),
                                                                   conventionPtr->businessDayCounvention(),
														           settlementDate,
														           1e-8, 100, 1.0) ;
                    
                    }

			static XLOPER returnOper ;
			ObjectHandler::scalarToOper(returnValue * 10000.0, returnOper) ;

			return & returnOper ;
	
		 } catch (std::exception & e) {

				ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
				static XLOPER returnOper ;
				returnOper.xltype = xltypeErr ;
				returnOper.val.err = xlerrValue ;

				return & returnOper ;

			}

	} ;