/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_initiate_fitted_bond_curve
#define xl_initiate_fitted_bond_curve

#include <qlo/conversions/coercehandle.hpp>
#include <qlo/bonds.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/conversions/opertovector.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFitting.hpp>
#include <ql/experimental/math/fittingMethod/stochasticSvenssonFitting/stochasticSvenssonFittingConstraint.hpp>

#include <bot/curve/fittedBondDiscountCurve/fittedBondDiscountCurveObject.hpp>
#include <bot/math/matrix/MatrixObject.hpp>
#include <bot/math/fittingMethod/stochasticFitting/stochasticFittingObject.hpp>
#include <bot/factory/currency/currencyFactory.hpp>
#include <bot/factory/calendar/calendarFactory.hpp>
#include <bot/factory/bondSelectionRule/bondSelectionRuleFactory.hpp>

        /* fitting de la forme NSS */
DLLEXPORT char * xlInitiateFittedBondCurve (const char * objectID_,
                                            const double * calculationDate_,
                                            const double * settlementDays_,
                                            const xloper * instruments_,
                                            const xloper * quote_,
                                            const char * currencyId_,
                                            const char * fittingMethodId_,
                                            const xloper * bondSelectionRule_,
                                            const xloper * trigger_) ;

#endif
