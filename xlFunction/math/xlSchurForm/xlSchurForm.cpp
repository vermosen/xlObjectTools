/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/math/xlSchurForm/xlSchurForm.hpp>

        /* fonction de calcul de la forme de Schur d'une matrice */
DLLEXPORT xloper * xlSchurForm(const char * objectID_,
                               const xloper * trigger_) {
    
    boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
        new ObjectHandler::FunctionCall("xlSchurForm")) ;

     try {

			QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

				// initialisation de la session
			ObjectHandler::validateRange(trigger_, "trigger") ;

				// on récupère la matrice
			OH_GET_REFERENCE(matrixObjectPtr, 
							 objectID_, 
							 QuantLibAddin::ublasMatrixObject,
							 boost::numeric::ublas::matrix<double>)

				// Schur (la conversion doit disparaitre à terme)
			QuantLib::SymmetricSchurDecomposition schur(
				QuantLibExtended::ublasMatrixToMatrix(* matrixObjectPtr)) ;

				// matrice de retour
			boost::numeric::ublas::matrix<double> returnMatrix (
				schur.eigenvalues().size(), schur.eigenvalues().size(), 0.0) ;

			for (unsigned int i = 0 ; i < schur.eigenvalues().size() ; i++)
					returnMatrix(i, i) = schur.eigenvalues()[i] ;

			static OPER returnOper ;
			ObjectHandler::ublasMatrixToOper(returnMatrix, returnOper) ;

			return & returnOper ;

		} catch (std::exception & e) {

				ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
				static OPER returnOper ;
				returnOper.xltype = xltypeErr ;
				returnOper.val.err = xlerrNA ;
	            
				return & returnOper ;

			}

	} ;
