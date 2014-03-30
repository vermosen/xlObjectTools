/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarBusinessDate/xlCalendarBusinessDate.hpp>

            /*Fonction de calcul des business date*/
DLLEXPORT double xlCalendarBusinessDate (double * calculationDate_, 
                                         char * calendarID_,
                                         long * spotDays_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlCalendarBusinessDate")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            return ObjectHandler::calendarFactory()(calendarID_).advance(QuantLib::Date(static_cast<QuantLib::BigInteger>(* calculationDate_)),
                                                                         * spotDays_,
                                                                         QuantLib::Days).serialNumber() ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                return 0.0 ;

            }

}       