/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateBondBootstrapHelper/xlInitiateBondBootstrapHelper.hpp>

        /* enregistre un helper pour un depôt */
DLLEXPORT xloper * xlInitiateBondBootstrapHelper (const char * objectId_,
                                                  const char * bondId_,
                                                  const double * bondPrice_,
                                                  const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateBondBootstrapHelper")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;


                OH_GET_REFERENCE(bondPtr,
                                 bondId_,
                                 QuantLibAddin::Bond,
                                 QuantLib::Bond)


                    // creation de la quote
                boost::shared_ptr<QuantLib::Quote> myQuote(
                    new QuantLib::SimpleQuote(* bondPrice_)) ;


                    // création du handler
                QuantLib::Handle<QuantLib::Quote> quoteHandler(myQuote) ;


                    // creation du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::bondBootstrapHelperValueObject> bondValueObject(
                    new QuantLibAddin::ValueObjects::bondBootstrapHelperValueObject(objectId_,
                                                                                       true)) ;


                    // creation du helper
                boost::shared_ptr<QuantLibAddin::bondBootstrapHelperObject> bondBootstrapObject(
                    new QuantLibAddin::bondBootstrapHelperObject(bondValueObject,
                                                                 bondPtr,
                                                                 quoteHandler,
                                                                 true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        bondBootstrapObject,
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