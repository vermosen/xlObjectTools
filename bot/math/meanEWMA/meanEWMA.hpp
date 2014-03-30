/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef mean_ewma
#define mean_ewma

#include <math.h>

#include <ql/timeseries.hpp>

#include <ql/qldefines.hpp>

        /* fonction de calcul de la moyenne EWMA d'une série */
double meanEWMA(const QuantLib::TimeSeries<double> & data,
				const QuantLib::Date & startDate_,
                const double * decay_) ;

#endif
