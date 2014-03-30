/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/period/register_period.hpp>

void registerPeriod() {

        ObjectHandler::periodFactory createPeriod ;

        createPeriod.registerType("D", new QuantLib::TimeUnit(QuantLib::Days)) ;
        createPeriod.registerType("W", new QuantLib::TimeUnit(QuantLib::Weeks)) ;
        createPeriod.registerType("M", new QuantLib::TimeUnit(QuantLib::Months)) ;
        createPeriod.registerType("Y", new QuantLib::TimeUnit(QuantLib::Years)) ;

    } ;