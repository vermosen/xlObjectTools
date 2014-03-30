/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/calendar/xlCalendarDaycount/xlCalendarDaycount.hpp>

        /*Fonction de calcul des daycount basis*/
DLLEXPORT double xlCalendarDaycount (double * calculationDate_, 
                                     double * endDate_,
                                     char * daycountBasis_) {


        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlCalendarDaycount")) ;


        try {


                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                return ObjectHandler::daycountFactory()(daycountBasis_).yearFraction(QuantLib::Date(static_cast<QuantLib::BigInteger>(* calculationDate_)),
                                                                                     QuantLib::Date(static_cast<QuantLib::BigInteger>(* endDate_))) ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    return 0 ;


                }


    }