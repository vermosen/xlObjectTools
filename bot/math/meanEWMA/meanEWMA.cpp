/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/math/meanEWMA/meanEWMA.hpp>

        /* fonction de calcul de la moyenne EWMA d'une série */
double meanEWMA(const QuantLib::TimeSeries<double> & data,
				const QuantLib::Date & startDate_,
                const double * decay_) {

		QL_REQUIRE(startDate_ >= data.firstDate() &&
				   startDate_ <= data.lastDate(), "date is out of range") ;

        double yt = 0.0 ;
        
		double sigma = 0.0 ;
        
		unsigned long i = 0 ;

		QuantLib::TimeSeries<double>::const_reverse_iterator It = data.rbegin() ;

		while (It->first > startDate_) {

				++It ;
			
			} ;

		while (It != data.rend()) {
			
			
                    yt += It->second * pow(* decay_, static_cast<double>(i)) ;
                    
					sigma += pow(* decay_, static_cast<double>(i)) ;	

					i++ ; ++It ;


			}


        return yt / (sigma + QL_EPSILON) ;


    }
