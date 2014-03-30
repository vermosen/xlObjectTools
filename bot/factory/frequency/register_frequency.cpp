/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/frequency/register_frequency.hpp>


void registerFrequency() {


        ObjectHandler::frequencyFactory createFrequency ;

        createFrequency.registerType("NoFrequency", new QuantLib::Frequency(QuantLib::NoFrequency)) ;

        createFrequency.registerType("Once", new QuantLib::Frequency(QuantLib::Once)) ;

        createFrequency.registerType("Annual", new QuantLib::Frequency(QuantLib::Annual)) ;

        createFrequency.registerType("Semi-Annual", new QuantLib::Frequency(QuantLib::Semiannual)) ;

        createFrequency.registerType("Quarterly", new QuantLib::Frequency(QuantLib::Quarterly)) ;

		createFrequency.registerType("Monthly", new QuantLib::Frequency(QuantLib::Monthly)) ;


    } ;