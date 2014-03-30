/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 08/08/2009
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlCurveReferenceDate/xlCurveReferenceDate.hpp>

    /* Fonction de calcul de la date de règlement des instruments */
DLLEXPORT double xlCurveReferenceDate (const char * curveId_,
                                       xloper * trigger_) {


         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlCurveSettlementDate")) ;


         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                    // on récupère la courbe des taux
                OH_GET_OBJECT(CurvePtr, curveId_, ObjectHandler::Object)

                QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
                    QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(CurvePtr) ;
                    
                return YieldCurveLibObj->referenceDate().serialNumber() ;


            } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                return 0.0 ;


            }


    }