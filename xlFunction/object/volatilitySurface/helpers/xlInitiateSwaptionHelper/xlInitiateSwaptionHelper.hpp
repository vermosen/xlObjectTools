/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_swaption_helper
#define xl_initiate_swaption_helper

#include <ql/handle.hpp>
#include <ql/quotes/simplequote.hpp>

#include <ohxl/convert_oper.hpp>
#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <bot/factory/businessDayConvention/businessDayConventionFactory.hpp>
#include <bot/factory/daycounter/daycountFactory.hpp>
#include <bot/factory/period/periodFactory.hpp>
#include <bot/volatilitySurface/helpers/swaptionHelper/swaptionHelperObject.hpp>
#include <bot/index/iborIndex/iborIndexObject.hpp>

#include <qlo/termstructures.hpp>
#include <qlo/index.hpp>

	// register a helper for a swaption from static data
DLLEXPORT xloper * xlInitiateSwaptionHelper(const char * objectId_,
											const double * maturity_,
											const double * length_,
											const double * volatility_,
											const char * index_,
											const xloper * fixedLegTenor_,
											const xloper * fixedLegDaycounter_,
											const xloper * floatLegDaycounter_,
											const char * termStructure_,
											const xloper * errorType_,
											const xloper * strike_,
											const xloper * nominal_,
											const xloper * trigger_);

#endif
