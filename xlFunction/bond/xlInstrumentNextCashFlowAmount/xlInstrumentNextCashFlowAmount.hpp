/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/08/10
 *  Copyright 2009. All /rights r/eserved.
 *
 */

#ifndef xl_instrument_next_cashflow_amount
#define xl_instrument_next_cashflow_amount

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/conversions/coerceobject.hpp>
#include <qlo/conversions/coercelibrarysame.hpp>
#include <qlo/bonds.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/instruments/bond.hpp>

        /* définit le montant du cashflow précédente */
DLLEXPORT xloper * xlInstrumentNextCashFlowAmount (const char * objectID_,
                                                   xloper * testDate_,
                                                   xloper * trigger_) ;

#endif
