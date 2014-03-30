/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateInterpolatedCurve/xlInitiateInterpolatedCurve.hpp>

        /* enregistre une courbe interpolée */
DLLEXPORT char * xlInitiateInterpolatedCurve (const char * objectID_,
                                              xloper * calculationDate_,
                                              const char * curveCalendarId_,
                                              xloper * helperId_,
                                              xloper * trigger_) {
    
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateInterpolatedCurve")) ;


         try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    /* contrôle des cellules */
                ObjectHandler::validateRange(trigger_, "trigger") ;

                ObjectHandler::validateRange(helperId_, "helper Id") ;

                ObjectHandler::validateRange(calculationDate_, "calculation Date") ;

                    /* conversion des xloper */
                ObjectHandler::ConvertOper myOper1(* calculationDate_) ;

                std::vector<std::string> helperId = ObjectHandler::operToVector<std::string>(
                    * helperId_, "helper Id") ;

                    /* calendrier de la courbe */
                QuantLib::Calendar curveCalendar
                    = ObjectHandler::calendarFactory()(std::string(curveCalendarId_)) ;

                    /* initialisation de la date d'évaluation */ 
                QuantLib::Date currentDate(
                    myOper1.missing() ? 
                    QuantLib::Date() : 
                    QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

                    /* ?? */
			    //QuantLib::Settings::instance().evaluationDate() = currentDate ;

                    /* le vecteur des helpers */
                std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > helperVector ;


                for (std::vector<std::string>::const_iterator It = helperId.begin() ; It != helperId.end() ; ++It) {


                        OH_GET_REFERENCE(helperPtr, * It, 
                                         QuantLibAddin::RateHelper, 
                                         QuantLib::RateHelper) ;

                        helperVector.push_back(helperPtr) ;


                    }


                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::interpolatedCurveValueObject> curveValueObject(
                    new QuantLibAddin::ValueObjects::interpolatedCurveValueObject(
                        objectID_,
                        currentDate.serialNumber(),
                        true)) ;

                    // instanciation de la courbe
                boost::shared_ptr<ObjectHandler::Object> myCurve(
                    new QuantLibAddin::interpolatedCurveObject(curveValueObject,
                                                               currentDate,
                                                               helperVector,
                                                               true,
                                                               std::vector<QuantLib::Handle<QuantLib::Quote> >(),
                                                               std::vector<QuantLib::Date>(),
                                                               CURVE_DEFAULT_ACCURACY)) ;


		            // stockage de la courbe
	            std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                        myCurve, 
                                                                        true) ; // on force la réécriture

                static char ret[XL_MAX_STR_LEN] ;

                ObjectHandler::stringToChar(returnValue, ret) ;

                return ret ;


        } catch (std::exception & e) {


                static char ret[XL_MAX_STR_LEN] ;

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                ObjectHandler::stringToChar(e.what(), ret) ;

                return ret ;


        }

    } ;
