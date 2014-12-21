/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/08/10
 *  Copyright 2009. All /rights r/eserved.
 *
 */

#include "xlInstrumentCostOfCarry.hpp"

// compute the cost-of-carry of the instrument
DLLEXPORT xloper * xlInstrumentCostOfCarry (const char * objectID_         ,
                                            const char * repoCurveId_      ,
                                            const double * instrumentPrice_,
                                            const double * carryStartDate_ ,
                                            const double * carryEndDate_   ,
                                            xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInstrumentCostOfCarry"));

    try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "");

        // trigger cell
        ObjectHandler::validateRange(trigger_, "trigger");

        // get the bond
        OH_GET_REFERENCE(instrumentPtr         ,
                            objectID_          ,
                            QuantLibAddin::Bond,
                            QuantLib::Bond     )

        // get the yield curve
        OH_GET_OBJECT(curvePtr, repoCurveId_, ObjectHandler::Object)

        QuantLib::Date carryStartDate(static_cast<QuantLib::BigInteger>(* carryStartDate_)),
                       carryEndDate  (static_cast<QuantLib::BigInteger> (* carryEndDate_  )) ;

        QuantLib::Handle<QuantLib::YieldTermStructure> YieldCurveLibObj =
            QuantLibAddin::CoerceHandle<QuantLibAddin::YieldTermStructure, QuantLib::YieldTermStructure>()(curvePtr) ;

        // control on the dates
        QL_REQUIRE(carryStartDate <= carryEndDate, 
			"end date is situated before start date");
        QL_REQUIRE(YieldCurveLibObj->referenceDate() <= carryStartDate, 
			"wrong curve reference date");

        // the amount to return
        double returnValue = 0.0;

        // check on the instrument dates
        QL_REQUIRE(instrumentPtr->maturityDate() >= carryEndDate, 
			"instrument matures before end date !");
        QL_REQUIRE(instrumentPtr->issueDate() <= carryStartDate, 
			"instrument issues after begin date !");

		// add the 
            /* on ajoute le montant à l'engagement capitalisé
                à la date de fin de la période de carry et 
                on retranche l'accrued final pour obtenir le clean price */
        returnValue += *instrumentPrice_ + instrumentPtr->accruedAmount(carryStartDate) ;

        returnValue *= (YieldCurveLibObj->discount(carryStartDate, true) 
            / YieldCurveLibObj->discount(carryEndDate, true) - 1);

            /* on parcourt les CF de l'instruments */
        for (std::vector<boost::shared_ptr<QuantLib::CashFlow> >::const_iterator
                It = instrumentPtr->cashflows().begin() ;
                It != instrumentPtr->cashflows().end() ; ++It) {

                    /* contrôles sur les dates de tombée/règlement */
                if(It->get()->date() >= carryStartDate && It->get()->date() <= carryEndDate)

                            /* montant CF_i * discount_j / discount_i */
                        returnValue += It->get()->amount() * (YieldCurveLibObj->discount(It->get()->date(), true)
                                        / YieldCurveLibObj->discount(carryEndDate, true) - 1) ;

                    }


        static OPER returnOper ;
        ObjectHandler::scalarToOper(returnValue, returnOper) ;
        return & returnOper ;

    } catch (std::exception & e) {

            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
            static XLOPER returnOper ;
            ObjectHandler::scalarToOper(e.what(), returnOper) ;

            return & returnOper ;

        }
};

