/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/daycounter/register_daycounter.hpp>


void registerDayCounter() {


        ObjectHandler::daycountFactory createDaycount ;

        createDaycount.registerType("ACT/ACT", new QuantLib::ActualActual(QuantLib::ActualActual::ISDA)) ;

        createDaycount.registerType("ACT/ACT NON-EOM", new QuantLib::ActualActual(QuantLib::ActualActual::ISDA)) ; // for BBG conversion

        createDaycount.registerType("ACT/ACT ISMA", new QuantLib::ActualActual(QuantLib::ActualActual::ISMA)) ;

        createDaycount.registerType("ACT/360", new QuantLib::Actual360()) ;

        createDaycount.registerType("ACT/365", new QuantLib::Actual365Fixed()) ;

        createDaycount.registerType("30/360", new QuantLib::Thirty360(QuantLib::Thirty360::BondBasis)) ;

        createDaycount.registerType("ISMA-30/360", new QuantLib::Thirty360(QuantLib::Thirty360::EurobondBasis)) ;

        createDaycount.registerType("30E/360", new QuantLib::Thirty360(QuantLib::Thirty360::EurobondBasis)) ;


    } ;