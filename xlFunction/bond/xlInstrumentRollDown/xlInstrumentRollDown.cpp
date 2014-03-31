/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 17/01/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/bond/xlInstrumentRollDown/xlInstrumentRollDown.hpp>
#include <qlo\bonds.hpp>

    /* Fonction de calcul des prix théoriques des instruments */
DLLEXPORT xloper * xlInstrumentRollDown (const char * instrumentId_,
                                         const char * curveId_,
                                         const double * endAccruedDate_,
                                         xloper * spread_,
                                         xloper * conventionId_,
                                         xloper * trigger_) {

     boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentRollDown")) ;

     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                /* trigger pour provoquer le recalcul */
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(spread_, "spread") ;

            ObjectHandler::validateRange(conventionId_, "convention Id") ;

            ObjectHandler::ConvertOper myOper1(* spread_), 
                                       myOper2(* conventionId_) ;

            QuantLib::Spread mySpread(
                myOper1.missing() ? 
                0.0 : static_cast<QuantLib::Spread>(myOper1) / 10000.0) ;

                /* on récupère la courbe de taux */
            OH_GET_OBJECT(curvePtr, curveId_, ObjectHandler::Object)

            QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
                QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;


                /* établissement des dates de règlement : 
                   la date d'évaluation est imposée par la courbe */
            QuantLib::Date fwdDate = 
                QuantLib::Date(static_cast<QuantLib::BigInteger>(* endAccruedDate_)) ;


                /* on construit une term structure translatée à la date fwd */
            boost::shared_ptr<QuantLib::YieldTermStructure> myImpliedTermStructure(
                new QuantLib::translatedTermStructure(YieldCurveLibObj, fwdDate)) ;


            #ifdef _DEBUG

            {
            
                    /* test sur les courbes */
                std::vector<QuantLib::Date> myDateVector ;  

                std::vector<double> originaleRate ;

                std::vector<double> finalRate ;

                for (unsigned int i = 0 ; i < 100 ; i++) {


                        QuantLib::Date tempDate(fwdDate.serialNumber() + i * 15) ;

                        myDateVector.push_back(tempDate) ;

                        originaleRate.push_back(YieldCurveLibObj->zeroRate(tempDate, QuantLib::Actual365Fixed(), QuantLib::Continuous)) ;

                        finalRate.push_back(myImpliedTermStructure->zeroRate(tempDate, QuantLib::Actual365Fixed(), QuantLib::Continuous)) ;

                        std::ostringstream mess ;

                        mess << tempDate << " : " << originaleRate[i] << ", " << finalRate[i] << "\n" ;

                        OutputDebugString(mess.str().c_str()) ;
                    

                    }
            
            
            }

            #endif



                /* récupération du bond */
            OH_GET_UNDERLYING(myBond,
						      instrumentId_,
						      QuantLibAddin::Bond,
						      QuantLib::Bond)

            QuantLib::Real fwdCleanPrice ;

            if (myOper2.missing()) {
                

                  fwdCleanPrice = QuantLib::BondFunctions::cleanPrice(myBond,
                                                                      myImpliedTermStructure,
                                                                      mySpread,
                                                                      QuantLib::Actual365Fixed(),
                                                                      QuantLib::Continuous,
                                                                      QuantLib::Annual,
                                                                      QuantLib::Unadjusted,
                                                                      myBond.settlementDate(fwdDate)) ;
                

                }

            else {
                
                        /* on récupère la convention */
                    OH_GET_REFERENCE(conventionPtr,
                                     static_cast<std::string>(myOper2),
                                     QuantLibAddin::interestRateConventionObject,
                                     QuantLib::InterestRate)

                    fwdCleanPrice = QuantLib::BondFunctions::cleanPrice(myBond,
                                                                        myImpliedTermStructure,
                                                                        mySpread,
                                                                        conventionPtr->dayCounter(),
                                                                        conventionPtr->compounding(),
                                                                        conventionPtr->frequency(),
                                                                        conventionPtr->businessDayConvention(),
                                                                        myBond.settlementDate(fwdDate)) ;          
                
                
                }


                /* variable de retour */
            static XLOPER returnOper ;

            ObjectHandler::scalarToOper(fwdCleanPrice, returnOper) ;

            return & returnOper ;


        } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static XLOPER returnOper ;

                ObjectHandler::scalarToOper(e.what(), returnOper) ;

                return & returnOper ;


            }


    }