/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */
#include <xlFunction/object/curveTransform/xlInitiateCurveShift/xlInitiateCurveShift.hpp>

        /* enregistre un shift de courbe */
DLLEXPORT xloper * xlInitiateCurveShift(const char * shiftName_,
                                        const xloper * gapVector_,
                                        const xloper * shiftVector_,
                                        const char * conventionId_,
                                        const xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlInitiateCurveShift")) ;

     try {


            QL_REQUIRE(! functionCall->calledByFunctionWizard(), "") ;

                /* déclaration du trigger */
            ObjectHandler::validateRange(trigger_, "trigger") ;

                /* on récupère la convention */
            OH_GET_OBJECT(conventionPtr, conventionId_, QuantLibAddin::interestRateConventionObject)

                /* conversion des données */
            std::vector<std::string> gapId = ObjectHandler::operToVector<std::string>(* gapVector_, "gapVector_") ;

            std::vector<double> shiftVector = ObjectHandler::operToVector<double>(* shiftVector_, "shiftVector_") ;

            QL_ENSURE(gapId.size() == shiftVector.size(), "unconsistant data set") ;

            // std::vector<boost::shared_ptr<QuantLib::Handle<QuantLib::gapQuote> > > myGapVector ;
            std::vector<QuantLib::Handle<QuantLib::gapQuote> > myGapVector ;
            for (unsigned int i = 0 ; i < gapId.size() ; i++) {
                
                    QuantLib::Handle<QuantLib::Quote> myHandle(
                        boost::shared_ptr<QuantLib::Quote>(
                        new QuantLib::SimpleQuote(shiftVector[i]))) ;

                    boost::shared_ptr<QuantLib::gapQuote> myGapQuote(
                        new QuantLib::gapQuote(myHandle, 
                                               ObjectHandler::periodFactory()(gapId[i]),
                                               conventionPtr->frequency(),
                                               conventionPtr->daycounter(),
                                               conventionPtr->compounding(),
                                               conventionPtr->businessDayConvention(),
                                               true)) ;

                    QuantLib::Handle<QuantLib::gapQuote> myGapHandle(myGapQuote) ;

                    myGapVector.push_back(myGapHandle) ;

                }

                // construction du value objet
            boost::shared_ptr<QuantLibAddin::ValueObjects::curveShiftValueObject> valueObject(
                new QuantLibAddin::ValueObjects::curveShiftValueObject(
                    shiftName_,
                    true)) ;

                // construction de l'objet
            boost::shared_ptr<ObjectHandler::Object> shiftObject(
                new QuantLibAddin::curveShiftObject(
                    valueObject,
                    myGapVector,
                    true)) ;

                // stockage de l'objet
            std::string returnValue =
                ObjectHandler::RepositoryXL::instance().storeObject(shiftName_, 
                                                                    shiftObject, 
                                                                    true) ; // on force la réécriture
            static OPER returnOper ;

            ObjectHandler::scalarToOper(returnValue, returnOper) ;

            return & returnOper ;


    } catch (std::exception & e) {


            ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

            static OPER returnOper ;

            ObjectHandler::scalarToOper(e.what(), returnOper) ;

            return & returnOper ;


        }


    }