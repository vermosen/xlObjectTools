/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlPriceFromZSpread/xlPriceFromZSpread.hpp>

        /* Fonction de calcul d'un prix théorique d'une obligation US */
DLLEXPORT xloper * xlPriceFromZSpread (const char * instrumentId_,
                                       const char * curveId_,
                                       xloper * zSpread_,
                                       xloper * conventionId_,
                                       xloper* settlementDate_,
                                       xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlPriceFromZSpread")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // validation
            ObjectHandler::validateRange(trigger_, "trigger") ;
            ObjectHandler::validateRange(zSpread_, "z spread") ;
            ObjectHandler::validateRange(conventionId_, "convention Id") ;
            ObjectHandler::validateRange(settlementDate_, "settlement Date") ;

                // conversion des xloper
            ObjectHandler::ConvertOper myOper1(* zSpread_),
                myOper2(* conventionId_),
                myOper3(* settlementDate_) ;

            QuantLib::Spread zSpread(
                myOper1.missing() ? 0.0 : static_cast<QuantLib::Spread>(myOper1) / 10000) ; // en bps

               // on récupère le bond
            OH_GET_REFERENCE(instrumentPtr,
                             instrumentId_,
                             QuantLibAddin::Bond,
                             QuantLib::Bond)


                // on récupère la courbe des taux
            OH_GET_REFERENCE(curvePtr,
                             curveId_,
                             QuantLibAddin::YieldTermStructure,
                             QuantLib::YieldTermStructure)


            double returnValue = 0.0 ;


				// la convention par défaut : ACT/365, continuous, annual, unadjusted
            if (myOper2.missing()) {
                
                
                    returnValue = QuantLib::BondFunctions::cleanPrice(
                        * instrumentPtr,
                        curvePtr,
                        zSpread, // en bps
                        QuantLib::Actual365Fixed(),
                        QuantLib::Continuous,
                        QuantLib::Annual,
                        QuantLib::Unadjusted,
                        QuantLib::Date(myOper3.missing() ? 
                            instrumentPtr->settlementDate(curvePtr->referenceDate()).serialNumber() :
                            static_cast<QuantLib::BigInteger>(myOper3))) ;
                
                
                
                }

            else {
                
                
			        OH_GET_REFERENCE(conventionPtr, 
                                     static_cast<std::string>(myOper2), 
							         QuantLibAddin::interestRateConventionObject,
							         QuantLib::InterestRate)

                    returnValue = QuantLib::BondFunctions::cleanPrice(
                        * instrumentPtr,
                        curvePtr,
                        static_cast<QuantLib::Spread>(myOper1) / 10000, // en bps
                        conventionPtr->dayCounter(),
                        conventionPtr->compounding(),
                        conventionPtr->frequency(),
                        conventionPtr->businessDayCounvention(),
                        QuantLib::Date(myOper3.missing() ? 
                            instrumentPtr->settlementDate(curvePtr->referenceDate()).serialNumber() :
                            static_cast<QuantLib::BigInteger>(myOper3))) ;       
                

                
                }

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
