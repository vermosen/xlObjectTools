/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/duration/register_duration.hpp>


void registerDuration() {


        ObjectHandler::durationFactory createFrequency ;

        createFrequency.registerType("Simple", new QuantLib::Duration::Type(QuantLib::Duration::Simple)) ;

        createFrequency.registerType("Macaulay", new QuantLib::Duration::Type(QuantLib::Duration::Macaulay)) ;

        createFrequency.registerType("Modified", new QuantLib::Duration::Type(QuantLib::Duration::Modified)) ;


    } ;