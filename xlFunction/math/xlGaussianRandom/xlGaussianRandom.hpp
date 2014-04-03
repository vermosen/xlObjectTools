/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_gaussian_random
#define xl_gaussian_random

#ifdef _DEBUG

#include <crtdbg.h>

#endif

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>

#include <ql/math/randomnumbers/mt19937uniformrng.hpp>
#include <ql/experimental/math/random/boxMullerGaussianVectorRng.hpp>

#include <bot/math/MatrixToOper/MatrixToOper.hpp>
#include <bot/math/Matrix/MatrixObject.hpp>


        /* enregistre une matrice réelle */
DLLEXPORT xloper * xlGaussianRandom (const char * meanVector_,
                                     const char * stdDevVector_,
                                     const xloper * trigger_) ;

#endif
