/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlCurveZeroRate/xlCurveZeroRate.hpp>

        /* Procure le taux zero coupon correspondant à une date */
DLLEXPORT double xlCurveZeroRate (const char * curveId_,
                                  const double * effectiveDate_,
                                  const char * conventionId_,
                                  xloper * trigger_) {
    
         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlCurveZeroRate")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    /* création de la date */
                QuantLib::Date effectiveDate(static_cast<QuantLib::BigInteger>(* effectiveDate_)) ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                    // on récupère la convention
                OH_GET_REFERENCE(conventionPtr, 
                                 conventionId_, 
                                 QuantLibAddin::interestRateConventionObject, 
                                 QuantLib::InterestRate)

                    // on récupère la courbe des taux
                OH_GET_OBJECT(CurvePtr, curveId_, ObjectHandler::Object)

                QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(CurvePtr) ;

                QL_ENSURE(effectiveDate > YieldCurveLibObj->referenceDate(), 
                          "invalid date !") ;

                return YieldCurveLibObj->zeroRate(effectiveDate,
                                                  conventionPtr->dayCounter(),
                                                  conventionPtr->compounding(),
                                                  conventionPtr->frequency(),
                                                  true) ;

            } catch (std::exception & e) {

                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
					std::string ss(e.what()) ;
					return 0.0 ;

            }

    }

