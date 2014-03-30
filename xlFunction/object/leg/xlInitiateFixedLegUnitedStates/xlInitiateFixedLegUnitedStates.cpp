/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/leg/xlInitiateFixedLegUnitedStates/xlInitiateFixedLegUnitedStates.hpp>

        /* enregistre une jambe à taux fixe */
DLLEXPORT xloper * xlInitiateFixedLegUnitedStates (const char * objectID_,
                                                   const double * effectiveDate_,
                                                   const xloper * firstCouponDate_,
                                                   const xloper * lastCouponDate_,
                                                   const double * maturityDate_,
                                                   const xloper * notional_,
                                                   const double * couponRate_,
                                                   const xloper * frequency_,
                                                   const xloper * daycounter_,
                                                   xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateFixedLegUnitedStates")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            // trigger pour provoquer le recalcul
        ObjectHandler::validateRange(trigger_, "trigger") ;

        ObjectHandler::validateRange(firstCouponDate_, "first Coupon Date") ;

        ObjectHandler::validateRange(lastCouponDate_, "last Coupon Date") ;

        ObjectHandler::validateRange(notional_, "notional") ;

        ObjectHandler::validateRange(frequency_, "frequency") ;

        ObjectHandler::validateRange(daycounter_, "daycounter") ;


			// Création des oper
        ObjectHandler::ConvertOper myOper1(* firstCouponDate_),
                                   myOper2(* lastCouponDate_),
                                   myOper3(* notional_),
                                   myOper4(* frequency_),
                                   myOper5(* daycounter_) ;


            // Construction du value object
        boost::shared_ptr<QuantLibAddin::ValueObjects::fixedLegUnitedStatesValueObject> myLegValueObject(
            new QuantLibAddin::ValueObjects::fixedLegUnitedStatesValueObject(objectID_,
                                                                   true)) ;

            // création des dates et contrôles sur les dates intermédiaires
        QuantLib::Date effectiveDate(QuantLib::Date(static_cast<QuantLib::BigInteger>(* effectiveDate_))) ;

        QuantLib::Date maturityDate(QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_))) ;

        QuantLib::Date firstCouponDate(myOper1.missing() ? 
            QuantLib::Date() : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper1))) ;

        QuantLib::Date lastCouponDate(myOper2.missing() ? 
            QuantLib::Date() : 
            QuantLib::Date(static_cast<QuantLib::BigInteger>(myOper2))) ;

        QuantLib::Real notional(myOper3.missing() ? 
            100.0 : 
            static_cast<QuantLib::Real>(myOper3)) ;

        QuantLib::Frequency frequency(myOper4.missing() ? 
            QuantLib::Semiannual : 
            ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper4))) ;

        QuantLib::DayCounter daycounter(myOper5.missing() ? 
            QuantLib::Thirty360() : 
            ObjectHandler::daycountFactory()(static_cast<std::string>(myOper5))) ;


            // instanciation de l'instrument
        boost::shared_ptr<QuantLibAddin::fixedLegUnitedStatesObject> myLegObject(
            new QuantLibAddin::fixedLegUnitedStatesObject(myLegValueObject,
                                                          effectiveDate,
                                                          firstCouponDate,
														  lastCouponDate,
                                                          maturityDate,
														  * couponRate_,
                                                          frequency,
														  daycounter,
														  QuantLib::Compounded,
														  notional,
                                                          QuantLib::ModifiedFollowing,
                                                          QuantLib::ModifiedFollowing, 
														  true,
                                                          true)) ;

            // stockage de l'objet
        std::string returnValue =
            ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                myLegObject, 
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