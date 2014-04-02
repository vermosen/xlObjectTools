/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/index/xlInitiateIborIndex/xlInitiateIborIndex.hpp>

        /* enregistre un index avec ses fixings */
DLLEXPORT char * xlInitiateIborIndex (const char * objectId_,
                                      const char * indexHistoryId_,
                                      const char * tenor_,
                                      const double * settlementDays_,
                                      const char * fixingCalendar_,
                                      const xloper * bdc_,
                                      const xloper * endOfMonth_,
                                      const char * dayCounter_,
                                      const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateIborIndex")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* initialisation de la session */
            ObjectHandler::validateRange(trigger_,    "trigger"     );
            ObjectHandler::validateRange(bdc_,        "bdc"         );
            ObjectHandler::validateRange(endOfMonth_, "end of month");

                /* conversion des xloper */
            ObjectHandler::ConvertOper myOper1(* bdc_),
                                       myOper2(* endOfMonth_) ;

            QuantLib::BusinessDayConvention bdc(
                myOper1.missing() ?
                QuantLib::Following : 
                ObjectHandler::businessDayConventionFactory()(
                    static_cast<std::string>(myOper1))) ;

            bool endOfMonth(
                myOper2.missing() ?
                false : 
                static_cast<bool>(myOper2)) ;


                /* on récupère l'historique des fixings */
            OH_GET_REFERENCE(indexHistoryPtr,
                             indexHistoryId_,
                             QuantLibAddin::TimeSeriesObject<QuantLib::Real>,
                             QuantLib::TimeSeries<QuantLib::Real>)

                /* Construction du value object */
			boost::shared_ptr<QuantLibAddin::ValueObjects::iborIndexValueObject> valueObject(
				new QuantLibAddin::ValueObjects::iborIndexValueObject) ;

                // instanciation de l'index
            boost::shared_ptr<QuantLibAddin::iborIndexObject> myIborIndex(
                new QuantLibAddin::iborIndexObject(valueObject,
                                                   std::string(objectId_),
                                                   ObjectHandler::periodFactory()(tenor_),
                                                   QuantLib::Natural(* settlementDays_),
                                                   ObjectHandler::calendarFactory()(fixingCalendar_),
                                                   bdc,
                                                   endOfMonth,
                                                   ObjectHandler::daycountFactory()(dayCounter_),
                                                   QuantLib::RelinkableHandle<QuantLib::YieldTermStructure>(),
                                                   true)) ;

                /* on insère les fixings */
            myIborIndex->addFixings(indexHistoryPtr->dates(),
                                    indexHistoryPtr->values(),
                                    true,
                                    true) ;

            // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(std::string(objectId_),
                                                                    myIborIndex,
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
