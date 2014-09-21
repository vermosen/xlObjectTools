/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_math_hpp
#define register_math_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/math/xlVolatilityEWMA/register_xlVolatilityEWMA.hpp>
#include <xlFunction/math/xlSchurEigenValues/register_xlSchurEigenValues.hpp>
#include <xlFunction/math/xlSchurEigenVector/register_xlSchurEigenVector.hpp>
#include <xlFunction/math/xlMeanEWMA/register_xlMeanEWMA.hpp>
#include <xlFunction/math/xlGaussianRandom/register_xlGaussianRandom.hpp>
#include <xlFunction/math/xlCovarianceMatrixEWMA/register_xlCovarianceMatrixEWMA.hpp>
#include <xlFunction/math/xlCorrelationMatrixEWMA/register_xlCorrelationMatrixEWMA.hpp>
#include <xlFunction/math/xlZScoreEWMA/register_xlZScoreEWMA.hpp>
#include <xlFunction/math/statistics/register_statistics.hpp>

inline void register_math(const XLOPER & xDll) {

            // register math
            registerxlVolatilityEWMA        (xDll);
			registerxlSchurEigenValues      (xDll);
            registerxlSchurEigenVector      (xDll);
            registerxlMeanEWMA              (xDll);
            registerxlGaussianRandom        (xDll);
            registerxlCovarianceMatrixEWMA  (xDll);
            registerxlZScoreEWMA            (xDll);
            registerxlCorrelationMatrixEWMA (xDll);
			register_statistics             (xDll);

    };

inline void unregister_math(const XLOPER & xDll) {

            // unregister math
            unregisterxlVolatilityEWMA        (xDll);
			unregisterxlSchurEigenValues      (xDll);
            unregisterxlSchurEigenVector      (xDll);
            unregisterxlMeanEWMA              (xDll);
            unregisterxlGaussianRandom        (xDll);
            unregisterxlCovarianceMatrixEWMA  (xDll);
            unregisterxlZScoreEWMA            (xDll);
            unregisterxlCorrelationMatrixEWMA (xDll);
			unregister_statistics             (xDll);

    };

#endif
