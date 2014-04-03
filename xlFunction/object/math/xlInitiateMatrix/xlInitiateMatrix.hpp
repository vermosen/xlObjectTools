/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_ublas_matrix
#define xl_initiate_ublas_matrix

#include <ohxl/conversions/validations.hpp>
#include <ohxl/repositoryxl.hpp>

#include <bot/math/matrix/matrixObject.hpp>
#include <bot/math/operToMatrix/operToMatrix.hpp>

#include <ql/errors.hpp>

        /* fonction qui instancie une matrice */
DLLEXPORT char * xlInitiateUblasMatrix(const char * objectID_,
                                       const xloper * matrix_,
                                       xloper * trigger_) ;

#endif