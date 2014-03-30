/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 29/10/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_is_active_instrument_yield
#define xl_is_active_instrument_yield

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/factory/bondSelectionRule/bondSelectionRuleFactory.hpp>

        /* Fonction qui détermine si un instrument est actif à une date donnée */
DLLEXPORT xloper * xlIsActiveInstrument (const char * instrumentId_,
                                         xloper * testDate_,
										 xloper * testRule_,
                                         xloper * trigger_) ;

#endif