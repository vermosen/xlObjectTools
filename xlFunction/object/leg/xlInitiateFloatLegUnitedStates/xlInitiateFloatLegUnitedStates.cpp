/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/leg/xlInitiatefloatLegUnitedStates/xlInitiatefloatLegUnitedStates.hpp>

        /* enregistre une jambe à taux flottant */
DLLEXPORT xloper * xlInitiateFloatLegUnitedStates (const char * objectID_,
                                                   const double * effectiveDate_,
                                                   xloper * firstCouponDate_,
                                                   xloper * lastCouponDate_,
                                                   const double * maturityDate_,
                                                   xloper * notional_,
                                                   const char * indexId_,
                                                   xloper * frequency_,
                                                   xloper * daycounter_,
                                                   xloper * spread_,
                                                   xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiatefloatLegUnitedStates")) ;

     try {


        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;


            // vérification des codes erreur
        ObjectHandler::validateRange(trigger_, "trigger") ;

        ObjectHandler::validateRange(firstCouponDate_, "first Coupon Date") ;

        ObjectHandler::validateRange(lastCouponDate_, "last Coupon Date") ;

        ObjectHandler::validateRange(notional_, "notional") ;

        ObjectHandler::validateRange(frequency_, "frequency") ;

        ObjectHandler::validateRange(daycounter_, "daycounter") ;

        ObjectHandler::validateRange(spread_, "spread") ;

            // Création des oper
        ObjectHandler::ConvertOper myOper1(* firstCouponDate_),
                                   myOper2(* lastCouponDate_),
                                   myOper3(* notional_),
                                   myOper4(* frequency_),
                                   myOper5(* daycounter_),
                                   myOper6(* spread_) ;

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
            QuantLib::Quarterly : 
            ObjectHandler::frequencyFactory()(static_cast<std::string>(myOper4))) ;

        QuantLib::DayCounter daycounter(myOper5.missing() ? 
            QuantLib::Actual360() : 
            ObjectHandler::daycountFactory()(static_cast<std::string>(myOper5))) ;

		QuantLib::Spread spread(myOper6.missing() ? 
            0.0 : 
            static_cast<QuantLib::Spread>(myOper6)) ;


            // on récupère l'index libor
        OH_GET_REFERENCE(iborIndexPtr, 
                         std::string(indexId_), 
                         QuantLibAddin::iborIndexObject,
                         QuantLib::IborIndex)    


            // Construction du value object
        boost::shared_ptr<QuantLibAddin::ValueObjects::floatLegUnitedStatesValueObject> myLegValueObject(
            new QuantLibAddin::ValueObjects::floatLegUnitedStatesValueObject(objectID_,
                                                                   true)) ;

            // instanciation de l'instrument
        boost::shared_ptr<QuantLibAddin::floatLegUnitedStatesObject> myLegObject(
            new QuantLibAddin::floatLegUnitedStatesObject(myLegValueObject,
                                                effectiveDate,
                                                firstCouponDate,
                                                lastCouponDate,
                                                maturityDate,
                                                iborIndexPtr,
                                                2,
                                                frequency,
                                                daycounter,
                                                notional,
                                                spread,
                                                QuantLib::ModifiedFollowing,
                                                QuantLib::ModifiedFollowing, 
                                                true, true)) ;


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