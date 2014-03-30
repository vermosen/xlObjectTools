/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/math/xlGaussianRandom/xlGaussianRandom.hpp>

        /* crée un vecteur aléatoire distribué selon une loi gaussienne multi-variée */
DLLEXPORT xloper * xlGaussianRandom (const char * meanVector_,
                                     const char * stdDevMatrixObject_,
                                     const xloper * trigger_) {

    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlGaussianRandom")) ;

     try {

            #ifdef _DEBUG


                _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF|_CRTDBG_ALLOC_MEM_DF) ;  

                _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE) ;

                _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT) ;


            #endif

            QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;
        
                // validation du trigger
            ObjectHandler::validateRange(trigger_, "trigger") ;

                // on récupère les matrices
            OH_GET_OBJECT (meanVectorObject, meanVector_, QuantLibAddin::MatrixObject)
                boost::shared_ptr<boost::numeric::::matrix<double> > meanVectorPtr ;
                meanVectorObject->getLibraryObject (meanVectorPtr) ;

            OH_GET_OBJECT (stdDevMatrixObject, stdDevMatrixObject_, QuantLibAddin::MatrixObject)
                boost::shared_ptr<boost::numeric::::matrix<double> > stdDevMatrixPtr ;
                stdDevMatrixObject->getLibraryObject (stdDevMatrixPtr) ;

                // contrôles
            QL_REQUIRE(meanVectorPtr->size2() == 1, "mean vector have to be a column vector") ;

            QL_REQUIRE(stdDevMatrixPtr->size1() == stdDevMatrixPtr->size2(), "non-square std deviation matrix") ;
            
            QL_REQUIRE(meanVectorPtr->size1() == stdDevMatrixPtr->size1(), "inconsistent data") ;

                // construction du vecteur de nombres aléatoires
            QuantLib::MersenneTwisterUniformRng twister ;

            boost::shared_ptr<QuantLibExtended::boxMullerGaussianVectorRng<QuantLib::MersenneTwisterUniformRng> > myGenerator(
                new QuantLibExtended::boxMullerGaussianVectorRng<QuantLib::MersenneTwisterUniformRng>(
                * meanVectorPtr, * stdDevMatrixPtr, twister)) ;

            boost::numeric::::matrix<double> returnMatrix = myGenerator->nextVector().value ;

                // résultat
            static OPER returnOper ;

            ObjectHandler::MatrixToOper<double>(returnMatrix, returnOper) ;

            return & returnOper ;



            // gestion des erreurs
        } catch (std::exception & e) {


                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;

                static OPER returnOper ;

                returnOper.xltype = xltypeErr ;

                returnOper.val.err = xlerrNA ;

                return & returnOper ;


            }


    } ;
