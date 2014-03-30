/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_btf
#define xl_initiate_btf

#include <ohxl/repositoryxl.hpp>

#include <ohxl/conversions/scalartooper.hpp>

#include <ohxl/conversions/validations.hpp>

#include <bot/instruments/bond/btf/btfObject.hpp>

#include <bot/instruments/bond/btf/btfValueObject.hpp>

    /* enregistre un btf */
DLLEXPORT xloper * xlInitiateBtf (const char * objectID_,
                                  const double * issueDate_,
                                  const double * maturityDate_,
                                  xloper * trigger_) ;

#endif
