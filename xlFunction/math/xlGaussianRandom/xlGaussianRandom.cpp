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
			OH_GET_REFERENCE(meanVectorPtr,
							 meanVector_,
							 QuantLibAddin::matrixObject,
							 QuantLib::Matrix)

			OH_GET_REFERENCE(stdDevMatrixPtr,
							 stdDevMatrixObject_,
							 QuantLibAddin::matrixObject,
							 QuantLib::Matrix)

                // contrôles
			QL_REQUIRE(meanVectorPtr->columns() == 1,						   "mean vector have to be a column vector");
            QL_REQUIRE(stdDevMatrixPtr->rows()  == stdDevMatrixPtr->columns(), "non-square std deviation matrix"       );
			QL_REQUIRE(meanVectorPtr->rows()    == stdDevMatrixPtr->rows(),	   "inconsistent data"					   );

                // construction du vecteur de nombres aléatoires
            QuantLib::MersenneTwisterUniformRng twister ;

            boost::shared_ptr<QuantLib::boxMullerGaussianVectorRng<QuantLib::MersenneTwisterUniformRng> > myGenerator(
                new QuantLib::boxMullerGaussianVectorRng<QuantLib::MersenneTwisterUniformRng>(
                meanVectorPtr->array(), * stdDevMatrixPtr, twister)) ;

            QuantLib::Array returnMatrix = myGenerator->nextVector().value ;

                // résultat
            static OPER returnOper ;
            ObjectHandler::VectorToOper(returnMatrix, returnOper) ;
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
