/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/object/interestRateConvention/xlInitiateInterestRate/xlInitiateInterestRate.hpp>

        /* enregistre une jambe à taux fixe */
DLLEXPORT xloper * xlInitiateInterestRate (const char * objectID_,
                                           const char * accrualID_,
                                           const char * compoundingID_,
                                           const char * frequencyID_,
                                           const char * businessDayConventionID_,
                                           xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateInterestRate")) ;

     try {


            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

                // trigger pour provoquer le recalcul
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // Construction du value object
            boost::shared_ptr<QuantLibAddin::ValueObjects::interestRateConventionValueObject> myRateValueObject(
                new QuantLibAddin::ValueObjects::interestRateConventionValueObject(objectID_,
                                                                                   true)) ;

                // instanciation de l'instrument
            boost::shared_ptr<QuantLibAddin::interestRateConventionObject> myRateObject(
                new QuantLibAddin::interestRateConventionObject(myRateValueObject,
                                                                ObjectHandler::daycountFactory()(accrualID_),
                                                                ObjectHandler::compoundingFactory()(compoundingID_),
                                                                ObjectHandler::frequencyFactory()(frequencyID_),
                                                                ObjectHandler::businessDayConventionFactory()(businessDayConventionID_),
                                                                true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(objectID_, 
                                                                    myRateObject, 
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