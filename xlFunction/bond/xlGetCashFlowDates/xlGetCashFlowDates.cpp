/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlGetCashFlowDates/xlGetCashFlowDates.hpp>

        /* fonction de récupération des dates de paiement d'un instrument */
DLLEXPORT xloper * xlGetCashFlowDates (const char * objectID_,
                                       xloper * trigger_) {
    

        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlGetCashFlowDates")) ;


        try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // le vecteur des dates
            std::vector<double> returnVector ;

            OH_GET_UNDERLYING(myBond, 
                              objectID_, 
                              QuantLibAddin::Bond, 
                              QuantLib::Bond)

            returnVector.push_back(myBond.issueDate().serialNumber()) ;

            for (unsigned int i = 0 ; i < myBond.cashflows().size() - 1 ; i++)

                            // recupération des dates
                        returnVector.push_back(myBond.cashflows()[i]->date().serialNumber()) ;

            static OPER returnOper ;
            ObjectHandler::vectorToOper<double>(returnVector, returnOper) ;
            return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                return 0 ;

            }

    } ;

