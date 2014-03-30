/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_bond_bootstrap_helper
#define xl_initiate_bond_bootstrap_helper


#include <ohxl/convert_oper.hpp>

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/validations.hpp>

#include <ohxl/conversions/scalartooper.hpp>


#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>

#include <bot/curve/bootstrapHelper/bondBootstrapHelper/bondBootstrapHelperObject.hpp>


#include <qlo/bonds.hpp>


#include <ql/handle.hpp>



        /* enregistre un helper pour un bond */
DLLEXPORT xloper * xlInitiateBondBootstrapHelper (const char * objectId_,
                                                  const char * bondId_,
                                                  const double * bondPrice_,
                                                  const xloper * trigger_) ;


#endif
