/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_fitting_r_square
#define xl_fitting_r_square

#include <qlo/conversions/coercetermstructure.hpp>

#include <qlo/conversions/coercehandle.hpp>


#include <ohxl/conversions/validations.hpp>

#include <ohxl/repositoryxl.hpp>


#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveObject.hpp>


        /* Fonction de conversion des T-bills discount -> prix */
DLLEXPORT double xlFittingRSquare(const char * objectID_,
                                  xloper * trigger_) ;

#endif
