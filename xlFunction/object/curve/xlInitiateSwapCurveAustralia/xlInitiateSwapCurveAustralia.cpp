/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateSwapCurveAustralia/xlInitiateSwapCurveAustralia.hpp>

        /* enregistre une courbe de Swap pour les conventions AUD */
DLLEXPORT char * xlInitiateSwapCurveAustralia (const char * objectID_,
                                               const double * calculationDate_,
                                               const xloper * instrumentTag_,
                                               const xloper * maturityTag_,
                                               const xloper * quote_,
                                               const double * convexityFactor_,
                                               const double * meanRevertingFactor_,
                                               const char * liborId1_,
                                               const char * liborId2_,
                                               xloper * trigger_) {
    
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateSwapCurveAustralia")) ;


     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* initialisation de la session */
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(instrumentTag_, "instrument Tag") ;

            ObjectHandler::validateRange(maturityTag_, "maturity Tag") ;

            ObjectHandler::validateRange(quote_, "quote") ;

                /* initialisation de la date d'évaluation */ 
			QuantLib::Date currentDate = QuantLib::Australia().adjust(
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

                // on récupère les taux Libor
            OH_GET_REFERENCE(libor3MPtr,	
							 std::string(liborId1_), 
							 QuantLibAddin::iborIndexObject,
							 QuantLib::IborIndex)

                // cloning
             boost::shared_ptr<QuantLib::IborIndex> ccLibor3MPtr 
                = libor3MPtr->clone(QuantLib::Handle<QuantLib::YieldTermStructure>()) ;

             OH_GET_REFERENCE(libor6MPtr,
							 std::string(liborId2_), 
							 QuantLibAddin::iborIndexObject, 
							 QuantLib::IborIndex)

                // cloning
             boost::shared_ptr<QuantLib::IborIndex> ccLibor6MPtr 
                = libor6MPtr->clone(QuantLib::Handle<QuantLib::YieldTermStructure>()) ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject> curveValueObject(
                new QuantLibAddin::ValueObjects::swapCurveAustraliaValueObject(
                    objectID_,
                    * calculationDate_,
                    true)) ;

                // instanciation de la courbe
            boost::shared_ptr<ObjectHandler::Object> mySwapCurve(
                new QuantLibAddin::swapCurveAustraliaObject(curveValueObject,
                                                            currentDate,
                                                            instrumentTag,
                                                            maturityTag,
                                                            quote,
                                                            * convexityFactor_,
                                                            ccLibor3MPtr,
                                                            ccLibor6MPtr,
                                                            * meanRevertingFactor_,
                                                            true,
                                                            AU_SWAP_ACCURACY)) ;

				// stockage de la courbe
			std::string returnValue3 =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    mySwapCurve, 
                                                                    true) ; // on force la réécriture

            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::stringToChar(returnValue3, ret) ;

            return ret ;


    } catch (std::exception & e) {


            static char ret[XL_MAX_STR_LEN] ;

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

            ObjectHandler::stringToChar(e.what(), ret) ;

            return ret ;


    }

} ;
