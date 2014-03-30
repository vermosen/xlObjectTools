/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/swap/xlSwapFlowsNPV/xlSwapFlowsNPV.hpp>

        /* fonction de récupération des dates de paiement d'un instrument */
DLLEXPORT xloper * xlSwapFlowsNPV (const char * objectID_,
								   const char * curveID_,
                                   xloper * trigger_) {


        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlSwapFlowNPV")) ;


        try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // le vecteur des NPV
            std::vector<double> returnVector ;

                // on récupère l'instrument
            OH_GET_OBJECT(objPtr, 
                          objectID_, 
                          ObjectHandler::Object)

				// on récupère la courbe
			OH_GET_OBJECT(curvePtr, 
                          curveID_, 
                          ObjectHandler::Object)

			QuantLib::Handle<QuantLib::YieldTermStructure> curveLibPtr =
				QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;

            OH_GET_REFERENCE(instrumentLibObj, 
                                objectID_, 
                                QuantLibAddin::Leg,
                                QuantLib::Leg)

			QL_REQUIRE(! instrumentLibObj->empty(), "no cashflows to display") ;

			for (QuantLib::Leg::const_iterator It = instrumentLibObj->begin() ;
				It != instrumentLibObj->end() ; ++It) {


					double returnNPV = 0.0 ;

					if (! It->get()->hasOccurred(curveLibPtr->referenceDate(), true))

						returnNPV = It->get()->amount() * curveLibPtr->discount(It->get()->date()) ;
                            
					returnVector.push_back(returnNPV) ;


                }

            static OPER returnOper ;
            ObjectHandler::vectorToOper<double>(returnVector, returnOper) ;

            return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
				ObjectHandler::scalarToOper(e.what(), returnOper) ;

                return & returnOper ;

        }

} ;

