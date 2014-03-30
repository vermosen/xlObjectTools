/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateKangarooBond/xlInitiateKangarooBond.hpp>

        /* enregistre un titre kangaroo */
DLLEXPORT xloper * xlInitiateKangarooBond (const char * objectID_,
                                           const double * issueDate_,
                                           const xloper * effectiveDate_,
                                           const xloper * firstCouponDate_,
                                           const xloper * lastCouponDate_,
                                           const double * maturityDate_,
                                           const double * couponRate_,
                                           const xloper * frequency_,
                                           const xloper * daycounter_,
                                           const xloper * settleDays_,
                                           const xloper * endOfMonth_,
                                           const xloper * exDividendDays_,
                                           const xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateKangarooBond")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

            ObjectHandler::validateRange(effectiveDate_, "effective Date") ;

            ObjectHandler::validateRange(firstCouponDate_, "first Coupon Date") ;

            ObjectHandler::validateRange(lastCouponDate_, "last Coupon Date") ;

            ObjectHandler::validateRange(frequency_, "frequency") ;

            ObjectHandler::validateRange(daycounter_, "daycounter") ;

            ObjectHandler::validateRange(settleDays_, "settle Days") ;

            ObjectHandler::validateRange(endOfMonth_, "end Of Month") ;

            ObjectHandler::validateRange(exDividendDays_, "ex Dividend Days") ;

            ObjectHandler::ConvertOper myOper1(* effectiveDate_),
                                       myOper2(* firstCouponDate_),
                                       myOper3(* lastCouponDate_),
                                       myOper4(* frequency_),
                                       myOper5(* daycounter_),
                                       myOper6(* settleDays_),
                                       myOper7(* endOfMonth_),
                                       myOper8(* exDividendDays_) ;

            QuantLib::Date effectiveDate(
                myOper1.missing() ?
                QuantLib::Date(static_cast<long>(* issueDate_)) :
                QuantLib::Date(static_cast<long>(myOper1))) ;

            QuantLib::Date firstCouponDate(
                myOper2.missing() ?
                QuantLib::Date() :
                QuantLib::Date(static_cast<long>(myOper2))) ;

            QuantLib::Date lastCouponDate(
                myOper3.missing() ?
                QuantLib::Date() :
                QuantLib::Date(static_cast<long>(myOper3))) ;

            QuantLib::Frequency bondFrequency(
                myOper4.missing() ?
                QuantLib::Semiannual :
                ObjectHandler::frequencyFactory()(static_cast<long>(myOper4))) ;

            QuantLib::DayCounter bondDaycounter(
                myOper5.missing() ?
                QuantLib::ActualActual(QuantLib::ActualActual::Bond) :
                ObjectHandler::daycountFactory()(static_cast<std::string>(myOper5))) ;

            QuantLib::Natural settleDays(
                myOper6.missing() ?
                3 : static_cast<long>(myOper6)) ;

            bool endOfMonth(
                myOper7.missing() ?
                false : static_cast<bool>(myOper7)) ;

            QuantLib::Natural exDividendDays(
                myOper8.missing() ?
                7 : static_cast<long>(myOper8)) ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::kangarooBondValueObject> myBondValueObject(
                new QuantLibAddin::ValueObjects::kangarooBondValueObject(objectID_,
                                                                         true)) ;
    			
			    /* cas à différencier : s'il y a 1 seul coupon intermédiaire */
		    boost::shared_ptr<QuantLibAddin::kangarooBondObject> myBondObject(
			    new QuantLibAddin::kangarooBondObject(
                    myBondValueObject,
                    QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
                    QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
                    bondFrequency,
                    bondDaycounter,
                    QuantLib::Rate(* couponRate_),
                    effectiveDate,
                    (firstCouponDate == lastCouponDate ? // true si Date() == Date()...
                        QuantLib::Date() : firstCouponDate),
                    lastCouponDate,
                    settleDays,
                    endOfMonth,
                    true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_,
                                                                    myBondObject,
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

