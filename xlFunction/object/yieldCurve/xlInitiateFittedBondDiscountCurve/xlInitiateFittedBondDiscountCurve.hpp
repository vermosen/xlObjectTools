/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_fitted_bond_discount_curve
#define xl_initiate_fitted_bond_discount_curve

#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFitting.hpp>
#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFittingConstraint.hpp>

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/opertovector.hpp>

#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveObject.hpp>
#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingObject.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/bondSelectionRule/bondSelectionRuleFactory.hpp>

// parametric fitted curve
DLLEXPORT char * xlInitiateFittedBondDiscountCurve (const char * objectID_           ,
                                                    const xloper * evaluationDate_   ,
                                                    const xloper * calculationDate_  ,
                                                    const xloper * instruments_      ,
                                                    const xloper * quote_            ,
                                                    const char * calendarID_         ,
                                                    const char * fittingMethodID_    ,
													const xloper * bondSelectionRule_,
                                                    const xloper * trigger_);

#endif
