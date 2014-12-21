/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/08/10
 *  Copyright 2009. All /rights r/eserved.
 *
 */

#ifndef xl_instrument_cost_of_carry
#define xl_instrument_cost_of_carry

#include <ql/termstructures/yieldtermstructure.hpp>

#include <ql/cashflows/cashflows.hpp>
#include <qlo/conversions/coercehandle.hpp>
#include <qlo/yieldtermstructures.hpp>
#include <qlo/bonds.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartoOper.hpp>

// compute the cost-of-carry of the instrument
DLLEXPORT xloper * xlInstrumentCostOfCarry (const char * objectID_         ,
                                            const char * repoCurveId_      ,
                                            const double * instrumentPrice_,
                                            const double * carryStartDate_ ,
                                            const double * carryEndDate_   ,
                                            xloper * trigger_               );

#endif
