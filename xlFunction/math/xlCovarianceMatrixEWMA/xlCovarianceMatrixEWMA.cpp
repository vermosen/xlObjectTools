/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlFunction/math/xlCovarianceMatrixEWMA/xlCovarianceMatrixEWMA.hpp>

        /* fonction de calcul de la matrice de variance-covariance d'un historique de taux */
DLLEXPORT xloper * xlCovarianceMatrixEWMA(const xloper * seriesId_,
                                          const double * decay_,
										  const double * startDate_,
                                          const bool * norm_,
                                          const xloper * trigger_) {

boost::shared_ptr<ObjectHandler::FunctionCall> functionCall(
    new ObjectHandler::FunctionCall("xlCovarianceMatrixEWMA")) ;

     try {

        QL_ENSURE(! functionCall->calledByFunctionWizard(), "") ;

            /* déclaration du trigger */
        ObjectHandler::validateRange(trigger_, "trigger") ;

            /* conversion des xloper */
        std::vector<std::string> seriesId = 
			ObjectHandler::operToVector<std::string>(* seriesId_, "seriesId") ;

            /* contrôle sur les dimensions */
        QL_ENSURE(seriesId.size() >= 2, "unconsistent data set") ;

            /* on récupére les séries variationnelles */
        std::vector<QuantLib::TimeSeries<double> > timeSeriesVector ;

        for (std::vector<std::string>::const_iterator It = seriesId.begin() ; 
			It != seriesId.end() ; ++It) {

                OH_GET_REFERENCE(TimeSeriesPtr, 
								 * It, 
								 QuantLibAddin::TimeSeriesObject<double>,
								 QuantLib::TimeSeries<double>)    
 
                timeSeriesVector.push_back(* TimeSeriesPtr) ;

            }

        std::vector<QuantLib::TimeSeries<double> > nTimeSeriesVector ;

            /* selon le mode choisi */
        if (* norm_ == true) {
            
                std::vector<QuantLib::TimeSeries<double> > deltaSeriesVector ;

                for (unsigned long i = 0 ; i < timeSeriesVector.size() ; i++)
                    
                        deltaSeriesVector.push_back(
							QuantLib::deltaTimeSeries<double>(timeSeriesVector[i])) ;
                    
                    /* création des vecteurs moyenne et std dev */
                std::vector<double> mean ;
                std::vector<double> variance ;

                for (std::vector<QuantLib::TimeSeries<double> >::const_iterator It = deltaSeriesVector.begin() ;
                    It < deltaSeriesVector.end() ; ++It) {

						variance.push_back(covarianceEWMA(* It, 
							* It, QuantLib::Date(static_cast<QuantLib::BigInteger>(* startDate_)), 
							decay_)) ;

                        mean.push_back(meanEWMA(* It, 
							QuantLib::Date(static_cast<QuantLib::BigInteger>(* startDate_)), 
							decay_)) ;

                    }

                    /* Mode normé */
                for (unsigned int i = 0 ; i < deltaSeriesVector.size() ; i++) {


                        std::vector<double> tempValues ;
                        std::vector<QuantLib::Date> tempDates ;

                        for (QuantLib::TimeSeries<double>::const_iterator It = deltaSeriesVector[i].begin() ;
                            It != deltaSeriesVector[i].end() ; ++It) {

                                tempDates.push_back(It->first) ;

                                tempValues.push_back((deltaSeriesVector[i][It->first] - mean[i]) / 
                                    pow((deltaSeriesVector[i].size() + 1) * variance[i], 0.5)) ;

                            }

                        QuantLib::TimeSeries<double> tempSeries(tempDates.begin(),
                                                                tempDates.end(),
                                                                tempValues.begin()) ;

                        nTimeSeriesVector.push_back(tempSeries) ;

                    }    

            }

        else {
            
                    /* Mode non normé */
                std::vector<double> mean ;

                for (std::vector<QuantLib::TimeSeries<double>>::const_iterator It = timeSeriesVector.begin() ;
                    It < timeSeriesVector.end() ; ++It)

                        mean.push_back(meanEWMA(* It, QuantLib::Date(
							static_cast<QuantLib::BigInteger>(* startDate_)), decay_)) ;

                    /* on se contente de centrer les séries */
                for (unsigned int i = 0 ; i < timeSeriesVector.size() ; i++) {

                        std::vector<double> tempValues ;
						std::vector<QuantLib::Date> tempDates ;

                        for (QuantLib::TimeSeries<double>::const_iterator It = timeSeriesVector[i].begin() ;
                            It != timeSeriesVector[i].end() ; ++It) {

                                tempDates.push_back(It->first) ;
                                tempValues.push_back(timeSeriesVector[i][It->first] - mean[i]) ;

                            }

                        QuantLib::TimeSeries<double> tempSeries(tempDates.begin(),
                                                                tempDates.end(),
                                                                tempValues.begin()) ;

                        nTimeSeriesVector.push_back(tempSeries) ;

                    }    
            
            }

            /* création de la matrice de retour */
        QuantLib::Matrix returnMatrix(
			nTimeSeriesVector.size(), nTimeSeriesVector.size()) ;
        
		for (unsigned int i = 0 ; i < nTimeSeriesVector.size() ; i++) {

            for (unsigned int j = 0 ; j <= i ; j++) {

                    returnMatrix[i][j] = covarianceEWMA(nTimeSeriesVector[i], 
														nTimeSeriesVector[j], 
														QuantLib::Date(static_cast<QuantLib::BigInteger>(* startDate_)),
														decay_) ;

					returnMatrix[j][i] = returnMatrix[i][j];

                }

            }

        static OPER returnOper ;
        ObjectHandler::MatrixToOper(returnMatrix, returnOper) ;
		return & returnOper ;

        } catch (std::exception & e) {

                ObjectHandler::RepositoryXL::instance().logError(e.what(), functionCall) ;
				return 0 ;

        }

}