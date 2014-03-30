/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_accrued_amount
#define xl_instrument_accrued_amount


#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/bonds.hpp>
#include <ql/instruments/bond.hpp>


        /* Fonction de calcul de l'accrued des instruments */
DLLEXPORT xloper * xlInstrumentAccruedAmount (const char * instrumentId_,
                                              xloper * settlementDate_,
                                              xloper * trigger_) ;

#endif