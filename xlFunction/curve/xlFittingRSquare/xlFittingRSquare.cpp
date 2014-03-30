/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/curve/xlFittingRSquare/xlFittingRSquare.hpp>

double xlFittingRSquare(const char * objectId_,
                        xloper * trigger_) {

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlFittingRSquare")) ;

             try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;

                     // on récupère la courbe des taux
                OH_GET_REFERENCE(curveTempPtr, 
                                 objectId_, 
                                 QuantLibAddin::fittedBondDiscountCurveObject,
                                 QuantLibExtended::stochasticSimplexFittedBondDiscountCurve)

                    /* récupération du coeficient de détermination de la courbe */
                return curveTempPtr->fittingRSquare() ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    return 0.0 ;


            }

    } ;