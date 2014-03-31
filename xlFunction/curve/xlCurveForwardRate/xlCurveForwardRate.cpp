/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlCurveForwardRate/xlCurveForwardRate.hpp>

        /* Fonction de calcul du taux forward */
DLLEXPORT double xlCurveForwardRate (const char * curveId_,
                                     const double * t1_,
                                     const double * t2_,
                                     const char * conventionId_,
                                     xloper * trigger_) {

         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlCurveForwardRate")) ;

         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    /* conversions et création du daycounter */
                QuantLib::Date t1(static_cast<QuantLib::BigInteger>(* t1_)) ;

                QuantLib::Date t2(static_cast<QuantLib::BigInteger>(* t2_)) ;

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

                QL_ENSURE(t1 >= YieldCurveLibObj->referenceDate() && t2 >= t1, 
                          "invalid date !") ;

                return YieldCurveLibObj->forwardRate(t1, t2,
                                                     conventionPtr->dayCounter(),
                                                     conventionPtr->compounding(),
                                                     conventionPtr->frequency(), 
                                                     false) ;

            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    return 0.0 ;


            }


    }