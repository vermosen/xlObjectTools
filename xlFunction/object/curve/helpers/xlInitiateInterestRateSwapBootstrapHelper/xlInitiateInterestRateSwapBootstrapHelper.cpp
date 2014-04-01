/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/curve/helpers/xlInitiateInterestRateSwapBootstrapHelper/xlInitiateInterestRateSwapBootstrapHelper.hpp>

        /* enregistre un helper pour un swap de taux */
DLLEXPORT xloper * xlInitiateInterestRateSwapBootstrapHelper (const char * objectId_,
                                                              const char * swapId_,
                                                              const double * quote_,
                                                              const xloper * discountCurve_,
                                                              const xloper * trigger_) {
    
        boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
            new ObjectHandler::FunctionCall("xlInitiateInterestRateSwapBootstrapHelper")) ;

         try {

                QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                    // trigger pour provoquer le recalcul
                ObjectHandler::validateRange(trigger_,		 "trigger") ;
                ObjectHandler::validateRange(discountCurve_, "discount Curve") ;

                    /* gestion de la courbe de discounting */
				ObjectHandler::ConvertOper myOper1(* discountCurve_) ;

				boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > discountHandle(
					new QuantLib::Handle<QuantLib::YieldTermStructure>) ;

				if (myOper1.missing()) {
					
						boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > tempHandle(
							new QuantLib::Handle<QuantLib::YieldTermStructure>()) ;

						discountHandle = tempHandle ;

					}

				else {
					
						OH_GET_REFERENCE(discountPtr,
										 static_cast<std::string>(myOper1),
										 QuantLibAddin::YieldTermStructure,
										 QuantLib::YieldTermStructure)

						boost::shared_ptr<QuantLib::Handle<QuantLib::YieldTermStructure> > tempHandle(
							new QuantLib::Handle<QuantLib::YieldTermStructure>(discountPtr)) ;

						discountHandle = tempHandle ;
						
					}

                    /* récupération du swap  */
                OH_GET_REFERENCE(swapPtr,
                                 swapId_,
                                 QuantLibAddin::interestRateSwapObject,
                                 QuantLib::vanillaSwap2)

                    // Construction du value object
                boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject> mySwapHelperValueObject(
                    new QuantLibAddin::ValueObjects::interestRateSwapBootstrapHelperValueObject(swapId_,
                                                                                                true)) ;

                QuantLib::Handle<QuantLib::Quote> quoteHandle(
                    boost::shared_ptr<QuantLib::Quote>(
                        new QuantLib::SimpleQuote(* quote_))) ;

                    // instanciation de l'instrument
                boost::shared_ptr<QuantLibAddin::interestRateSwapBootstrapHelperObject> mySwapHelperObject(
                    new QuantLibAddin::interestRateSwapBootstrapHelperObject(mySwapHelperValueObject,
                                                                             quoteHandle,
                                                                             swapPtr,
                                                                             * discountHandle,
                                                                             true)) ;

                    // stockage de l'objet
                std::string returnValue =
                    ObjectHandler::RepositoryXL::instance().storeObject(objectId_,
                                                                        mySwapHelperObject,
                                                                        true) ;


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