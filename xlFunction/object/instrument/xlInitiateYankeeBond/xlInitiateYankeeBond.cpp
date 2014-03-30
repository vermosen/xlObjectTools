/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/instrument/xlInitiateYankeeBond/xlInitiateYankeeBond.hpp>

        /* enregistre une obligationdu trésor US */
DLLEXPORT xloper * xlInitiateYankeeBond (const char * objectID_,
                                         const double * issueDate_,
                                         const double * effectiveDate_,
                                         const double * firstCouponDate_,
                                         const double * lastCouponDate_,
                                         const double * maturityDate_,
                                         const double * couponRate_,
                                         const double * frequency_,
                                         const char * daycounter_,
                                         const double * settleDays_,
                                         const bool * endOfMonth_,
                                         xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateYankeeBond")) ;

     try {

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::yankeeBondValueObject> myBondValueObject(
                new QuantLibAddin::ValueObjects::yankeeBondValueObject(objectID_,
                                                                       true)) ;
    			
			    // cas à différencier : s'il y a 1 seul coupon intermédiaire
		    boost::shared_ptr<QuantLibAddin::yankeeBondObject> myBondObject(
			    new QuantLibAddin::yankeeBondObject(
				    myBondValueObject,
				    QuantLib::Date(static_cast<QuantLib::BigInteger>(* issueDate_)),
				    QuantLib::Date(static_cast<QuantLib::BigInteger>(* maturityDate_)),
				    ObjectHandler::frequencyFactory()(static_cast<int>(* frequency_)),
				    ObjectHandler::daycountFactory()(daycounter_),
				    QuantLib::Rate(* couponRate_),
				    QuantLib::Date(static_cast<QuantLib::BigInteger>(* effectiveDate_)),
				    (* firstCouponDate_ == * lastCouponDate_ ? 
					    QuantLib::Date() : 
					    QuantLib::Date(static_cast<QuantLib::BigInteger>(* firstCouponDate_))),
				    QuantLib::Date(static_cast<QuantLib::BigInteger>(* lastCouponDate_)),
                    static_cast<QuantLib::Natural>(* settleDays_),
                    * endOfMonth_, true)) ;

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

