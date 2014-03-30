/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateSwapCurveUnitedStates/xlInitiateSwapCurveUnitedStates.hpp>

        /* enregistre une courbe de Swap pour les conventions USD */
DLLEXPORT char * xlInitiateSwapCurveUnitedStates (const char * objectID_,
                                                  const double * calculationDate_,
                                                  const xloper * instrumentTag_,
                                                  const xloper * maturityTag_,
                                                  const xloper * quote_,
                                                  const double * convexityFactor_,
                                                  const double * meanRevertingFactor_,
                                                  const char * liborId_,
                                                  xloper * trigger_) {
    
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateSwapCurve")) ;


     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* initialisation de la session */
            ObjectHandler::validateRange(trigger_, "trigger") ;
                
                /* initialisation de la date d'évaluation */ 
			QuantLib::Date currentDate = QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement).adjust(
                QuantLib::Date(static_cast<QuantLib::BigInteger>(* calculationDate_))) ;

                /* conversion des xloper */
            std::vector<std::string> instrumentTag = ObjectHandler::operToVector<std::string>(
                * instrumentTag_, "instument tag") ;

            std::vector<std::string> maturityTag = ObjectHandler::operToVector<std::string>(
                * maturityTag_, "maturity tag") ;

            std::vector<QuantLib::Rate> quote = ObjectHandler::operToVector<double>(
                * quote_, "quote") ;

            QL_ENSURE(instrumentTag.size() == maturityTag.size() 
                && instrumentTag.size() == quote.size(), "wrong instrument set") ;

                // on récupère le taux Libor
            OH_GET_REFERENCE(liborPtr,	
							 std::string(liborId_), 
							 QuantLibAddin::iborIndexObject, 
                             QuantLib::IborIndex)

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject> curveValueObject(
                new QuantLibAddin::ValueObjects::swapCurveUnitedStatesValueObject(
                    objectID_,
                    * calculationDate_,
                    true)) ;

                // instanciation de la courbe
            boost::shared_ptr<ObjectHandler::Object> mySwapCurve(
                new QuantLibAddin::swapCurveUnitedStatesObject(curveValueObject,
                                                               currentDate,
                                                               instrumentTag,
                                                               maturityTag,
                                                               quote,
                                                               * convexityFactor_,
                                                               liborPtr,
                                                               * meanRevertingFactor_,
                                                               true,
                                                               US_SWAP_ACCURACY)) ;

				// on restocke un nouvel index des bors
			boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> valueObject(
				new QuantLibAddin::ValueObjects::iborIndexValueObject) ;


				// stockage de la courbe
			std::string returnValue2 =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    mySwapCurve, 
                                                                    true) ; // on force la réécriture

            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::stringToChar(returnValue2, ret) ;

            return ret ;


    } catch (std::exception & e) {


            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

            ObjectHandler::stringToChar(e.what(), ret) ;

            return ret ;


    }

} ;
