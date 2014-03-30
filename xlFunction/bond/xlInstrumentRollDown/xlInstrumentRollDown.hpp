/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef xl_instrument_roll_down
#define xl_instrument_roll_down

#include <qlo/conversions/coercehandle.hpp>

#include <ohxl/repositoryxl.hpp>
#include <ohxl/conversions/validations.hpp>
#include <ohxl/convert_oper.hpp>
#include <ohxl/conversions/scalartooper.hpp>

#include <qlo/yieldtermstructures.hpp>

#include <ql/pricingengines/bond/bondfunctions.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>

#include <bot/tools/interestRateConvention/interestRateConventionObject.hpp>

#include <qle/termStructure/translatedTermStructure/translatedTermStructure.hpp>

        /* Fonction de calcul du roll-down d'un bond. Le but de la 
           procédure est d'établir l'effet du temps sur l'appréciation 
           du taux (effet croisé dtdr). Ainsi, on se propose de 
           repricer l'instrument à une date future donnée avec 
           une structure par terme stable, de calculer l'appréciation
           en taux et de reporter A AUJOURD'HUI l'appréciation en 
           taux du papier. */
DLLEXPORT xloper * xlInstrumentRollDown (const char * instrumentId_,
                                         const char * curveId_,
                                         const double * endAccruedDate_,
                                         xloper * spread_,
                                         xloper * conventionId_,
                                         xloper * trigger_) ;


#endif