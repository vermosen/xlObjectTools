/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/index/xlInitiateOvernightIndex/xlInitiateOvernightIndex.hpp>

        /* enregistre un index overnight avec ses fixings */
DLLEXPORT char * xlInitiateOvernightIndex (const char * objectId_,
                                           const xloper * indexHistoryId_,
                                           const xloper * settlementDays_,
                                           const char * fixingCalendar_,
                                           const char * dayCounter_,
                                           const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateOvernightIndex")) ;

     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;


                /* initialisation de la session */
            ObjectHandler::validateRange(trigger_, "trigger") ;

			ObjectHandler::validateRange(indexHistoryId_, "index History Id") ;

			ObjectHandler::validateRange(settlementDays_, "settlement Days") ;


                /* conversion des xloper */
            ObjectHandler::ConvertOper myOper1(* indexHistoryId_),
									   myOper2(* settlementDays_) ;


            QuantLib::Natural settlementDays(
                myOper2.missing() ?
                0 : 
                static_cast<long>(myOper2)) ;


			boost::shared_ptr<QuantLib::TimeSeries<QuantLib::Real> > myTimeSeriesPtr ;

                /* on récupère l'historique des fixings */
			if (myOper1.missing()) {
			
					boost::shared_ptr<QuantLib::TimeSeries<QuantLib::Real> > tempPtr(
						new QuantLib::TimeSeries<QuantLib::Real>()) ;

					myTimeSeriesPtr = tempPtr ;
			
				} 
			
			else {
			
					OH_GET_REFERENCE(tempPtr,
									 static_cast<std::string>(myOper1),
									 QuantLibAddin::TimeSeriesObject<QuantLib::Real>,
									 QuantLib::TimeSeries<QuantLib::Real>)

					myTimeSeriesPtr = tempPtr ;
			
				}

                /* Construction du value object */
			boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexValueObject> valueObject(
				new QuantLibAddin::ValueObjects::overnightIndexValueObject) ;

                // instanciation de l'index
            boost::shared_ptr<QuantLibAddin::overnightIndexObject> myIborIndex(
                new QuantLibAddin::overnightIndexObject(valueObject,
                                                        objectId_,
                                                        settlementDays,
                                                        ObjectHandler::calendarFactory()(fixingCalendar_),
                                                        ObjectHandler::daycountFactory()(dayCounter_),
                                                        QuantLib::RelinkableHandle<QuantLib::YieldTermStructure>(), // pas forwardable
                                                        true)) ;

                /* on insère les fixings */
            myIborIndex->addFixings(myTimeSeriesPtr->dates(),
                                    myTimeSeriesPtr->values(),
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
