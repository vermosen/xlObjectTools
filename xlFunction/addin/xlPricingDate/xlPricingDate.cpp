/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/addin/xlPricingDate/xlPricingDate.hpp>

        /* fonction de récupération la date de pricing */
DLLEXPORT double xlPricingDate (xloper * date_,
                                xloper * trigger_) {

         boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlPricingDate")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    /* recherche de code erreur */
                ObjectHandler::validateRange(date_, "date") ;

                ObjectHandler::validateRange(trigger_, "trigger") ;

                    /* les XLOPER */
                ObjectHandler::ConvertOper myOper(* date_) ;

                if (! myOper.missing())

                        QuantLib::Settings::instance().evaluationDate() = 
                            QuantLib::Date(static_cast<long>(myOper)) ;

                return QuantLib::Settings::instance().evaluationDate().value().serialNumber() ;

            } catch (std::exception & e) {

                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                    return 0.0 ;

            }

    }