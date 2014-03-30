/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateDepositBootstrapHelper/xlInitiateDepositBootstrapHelper.hpp>

        /* enregistre un helper pour un depôt */
DLLEXPORT xloper * xlInitiateDepositBootstrapHelper (const char * objectId_,
                                                     const char * depositId_,
                                                     const double * depositPrice_,
                                                     const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateDepositBootstrapHelper")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;


                OH_GET_REFERENCE(depositPtr,
                                 depositId_,
                                 QuantLibAddin::depositObject,
                                 QuantLibExtended::deposit)


                    // creation de la quote
                boost::shared_ptr<QuantLib::Quote> myQuote(
                    new QuantLib::SimpleQuote(* depositPrice_)) ;


                    // création du handler
                QuantLib::Handle<QuantLib::Quote> quoteHandler(myQuote) ;


                    // creation du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject> depositValueObject(
                    new QuantLibAddin::ValueObjects::depositBootstrapHelperValueObject(objectId_,
                                                                                       true)) ;

                    // creation du helper
                boost::shared_ptr<QuantLibAddin::depositBootstrapHelperObject> depositBootstrapObject(
                    new QuantLibAddin::depositBootstrapHelperObject(depositValueObject,
                                                                    depositPtr,
                                                                    quoteHandler,
                                                                    true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        depositBootstrapObject,
                                                                        true) ; // on force la réécriture


                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(returnValue, returnOper) ;

                return & returnOper ;


            } catch (std::exception & e) {


                    ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                    static XLOPER returnOper ;

                    ObjectHandler::scalarToOper(e.what(), returnOper) ;

                    return & returnOper ;


            }


    } ;