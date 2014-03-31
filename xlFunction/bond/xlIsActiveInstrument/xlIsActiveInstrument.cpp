/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlIsActiveInstrument/xlIsActiveInstrument.hpp>
#include <qlo/bonds.hpp>

        /* Fonction qui détermine si un instrument est actif à une date donnée */
DLLEXPORT xloper * xlIsActiveInstrument (const char * instrumentId_,
                                         xloper * testDate_,
										 xloper * testRule_,
                                         xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlIsActiveInstrument")) ;

     try {

            QL_REQUIRE(! functionCall->calledByFunctionWizard(), "") ;
            
                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;
            ObjectHandler::validateRange(testDate_, "test date") ;

                // transformation de la date
            ObjectHandler::ConvertOper myOper1(* testDate_),
									   myOper2(* testRule_) ;

			bool returnValue = false ;

            QuantLib::bondSelectionRule myRule =
				(myOper2.missing() ?
				 QuantLib::activeRule() :
				 ObjectHandler::bondSelectionRuleFactory()(
				     static_cast<std::string>(myOper2))) ;
      
                // on récupère l'instrument pointé
            OH_GET_UNDERLYING(myBond, 
                              instrumentId_, 
                              QuantLibAddin::Bond, 
                              QuantLib::Bond)

            QuantLib::Date testDate(
                myOper1.missing() ? 
                QuantLib::Date() : 
                QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

            if (myRule.isActive(myBond, testDate)) returnValue = true ;

            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(returnValue, returnOper) ;

            return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
                static XLOPER returnOper ;
                returnOper.xltype = xltypeErr ;
                returnOper.val.err = xlerrValue ;

                return & returnOper ;

            }

    } ;
