/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#include <xlFunction/object/curve/xlInitiateOvernightIndexedBootstrapHelper/xlInitiateOvernightIndexedBootstrapHelper.hpp>

        /* enregistre un helper pour un swap OIS */
DLLEXPORT xloper * xlInitiateOvernightIndexedBootstrapHelper (const char * objectId_,
                                                              const char * indexId_,
															  const double * maturityDate_,
                                                              const double * swapQuote_,
                                                              const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateOvernightIndexedBootstrapHelper")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_, "trigger") ;


                OH_GET_REFERENCE(indexPtr,
                                 indexId_,
                                 QuantLibAddin::overnightIndexObject,
                                 QuantLib::OvernightIndex)


                    // creation de la quote
                boost::shared_ptr<QuantLib::Quote> myQuote(
                    new QuantLib::SimpleQuote(* swapQuote_)) ;


                    // création du handle
                QuantLib::Handle<QuantLib::Quote> quoteHandler(myQuote) ;


                    // creation du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject> swapOISValueObject(
                    new QuantLibAddin::ValueObjects::overnightIndexedSwapBootstrapHelperValueObject(objectId_,
                                                                                       true)) ;

                    // creation du helper
                boost::shared_ptr<QuantLibAddin::overnightIndexedSwapBootstrapHelperObject> swapOISBootstrapObject(
                    new QuantLibAddin::overnightIndexedSwapBootstrapHelperObject(swapOISValueObject,
                                                                                 QuantLib::Settings::instance().evaluationDate().value(),
                                                                                 QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
																				 quoteHandler,
																				 indexPtr,
                                                                                 true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        swapOISBootstrapObject,
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