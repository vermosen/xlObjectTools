/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/experimental/xlInitiateSwapCurve/xlInitiateSwapCurve.hpp>

        /* enregistre une courbe de Swap */
DLLEXPORT xloper * xlInitiateSwapCurve (const char * objectID_,
                                        const xloper * calculationDate_,
                                        const xloper * curveCalendarId_,
                                        const xloper * helperId_,
                                        const xloper * trigger_) {
        
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateSwapCurve")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // ranges validation
				ObjectHandler::validateRange(trigger_, "trigger") ;
                ObjectHandler::validateRange(calculationDate_, "calculation Date") ;
                ObjectHandler::validateRange(curveCalendarId_, "curve Calendar Id") ;
                ObjectHandler::validateRange(helperId_, "helper Id") ;

                    // XLOPERs
                ObjectHandler::ConvertOper myOper1(* calculationDate_),
                                           myOper2(* curveCalendarId_) ;

                QuantLib::Calendar calendar(
                    myOper2.missing() ? 
                    QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement) : 
                    ObjectHandler::calendarFactory()(static_cast<std::string>(myOper2))) ;

                QuantLib::Date calculationDate(
                    myOper1.missing() ? 
                    QuantLib::Date() : 
                    static_cast<QuantLib::Date>(myOper1)) ;

                std::vector<std::string> helperId = ObjectHandler::operToVector<std::string>(
                    * helperId_, "instrument Id") ;

                std::vector<boost::shared_ptr<QuantLib::BootstrapHelper<QuantLib::YieldTermStructure> > > helperVector ;

                for (std::vector<std::string>::const_iterator It = helperId.begin() ; It != helperId.end() ; ++It) {

                        if (* It != "") {

                                OH_GET_REFERENCE(helperPtr,
                                                 * It,
                                                 QuantLibAddin::RateHelper,
                                                 QuantLib::RateHelper)

                                helperVector.push_back(helperPtr) ;

                            }

                    }

                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::swapCurveValueObject> curveValueObject(
                    new QuantLibAddin::ValueObjects::swapCurveValueObject(
                        objectID_,
                        calculationDate.serialNumber(),
                        true)) ;

                    // instanciation de la courbe
                boost::shared_ptr<ObjectHandler::Object> mySwapCurve(
                    new QuantLibAddin::swapCurveObject(curveValueObject,
                                                       calculationDate,
                                                       helperVector,
                                                       true,
                                                       std::vector<QuantLib::Handle<QuantLib::Quote> >(),
                                                       std::vector<QuantLib::Date>(),
                                                       SWAP_ACCURACY)) ;

                    // stockage de la courbe
	            std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                        mySwapCurve,
                                                                        true) ; // on force la réécriture

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(0.0, returnOper) ;

                return & returnOper ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    static XLOPER returnOper ;

                    ObjectHandler::scalarToOper(e.what(), returnOper) ;

                    return & returnOper ;


            }


    } ;
