/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/math/covarianceEWMA/covarianceEWMA.hpp>

        /* fonction de calcul de la covariance EWMA d'une série */
double covarianceEWMA(const QuantLib::TimeSeries<double> & vecA,
                      const QuantLib::TimeSeries<double> & vecB,
					  const QuantLib::Date & startDate_,
                      const double * decay_) {

			// control over the time range
		QL_REQUIRE(startDate_ >= vecA.firstDate() &&
				   startDate_ <= vecB.lastDate(), "date is out of range") ;

            // time series are consistent one to each other
        QL_REQUIRE(vecA.dates() == vecB.dates(), 
                   "unappropriate covariance computation") ;

        double xt = 0.0 ;
        
		double sigma = 0.0 ;
        
		unsigned long i = 0 ;

        QuantLib::TimeSeries<double>::const_reverse_iterator ItA = vecA.rbegin() ;

        QuantLib::TimeSeries<double>::const_reverse_iterator ItB = vecB.rbegin() ;

		while (ItA->first > startDate_) {


				++ItA ;

				++ItB ;
			

			} ;

		while (ItA != vecA.rend()) {
			
			
                    xt += (ItA->second * ItB->second * pow(* decay_, static_cast<double>(i))) ;
                    
					sigma += pow(* decay_, static_cast<double>(i)) ;	

					i++ ; ++ItA ; ++ ItB ;


			}

        return xt / (sigma + QL_EPSILON) ;

    }
