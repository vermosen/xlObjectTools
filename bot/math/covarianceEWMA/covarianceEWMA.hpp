/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef standard_deviation_ewma
#define standard_deviation_ewma

#include <math.h>

#include <ql/timeseries.hpp>

#include <ql/qldefines.hpp>

        /* fonction de calcul de la covariance EWMA d'une série */
double covarianceEWMA(const QuantLib::TimeSeries<double> & vecA,
                      const QuantLib::TimeSeries<double> & vecB,
					  const QuantLib::Date & startDate_,
                      const double * decay_) ;

#endif
