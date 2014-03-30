/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlRecoverFittingParameters/xlRecoverFittingParameters.hpp>

        /* permet la récumération du vecteur des paramètres de fitting */
DLLEXPORT xloper * xlRecoverFittingParameters (const char * curveId_,
                                               const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlRecoverFittingParameters")) ;

         try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // on récupère la courbe des taux
            OH_GET_REFERENCE(curveTempPtr, 
                             curveId_, 
                             QuantLibAddin::fittedBondDiscountCurveObject,
                             QuantLibExtended::stochasticSimplexFittedBondDiscountCurve)

                // the parameter vector
            boost::numeric::ublas::matrix<double> returnVector = curveTempPtr->fitResults().solution() ;

            static OPER returnOper ;

            ObjectHandler::ublasMatrixToOper(returnVector, returnOper) ;

            return & returnOper ;


        } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(e.what(), returnOper) ;

                return & returnOper ;


            }


    } ;
