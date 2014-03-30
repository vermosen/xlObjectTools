/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "register_calendars.hpp"

void registerCalendars() {


        ObjectHandler::calendarFactory createCalendar ;

        createCalendar.registerType("USD", new QuantLib::UnitedStates(QuantLib::UnitedStates::GovernmentBond)) ;
        createCalendar.registerType("EUR", new QuantLib::TARGET()) ;
        createCalendar.registerType("GBP", new QuantLib::UnitedKingdom(QuantLib::UnitedKingdom::Settlement)) ;
        createCalendar.registerType("AUD", new QuantLib::Australia()) ;
        createCalendar.registerType("XAU", new QuantLib::UnitedKingdom(QuantLib::UnitedKingdom::Metals)) ;

		createCalendar.registerType("USD LIBOR", new QuantLib::JointCalendar(
                                    QuantLib::UnitedStates(QuantLib::UnitedStates::Settlement),
                                    QuantLib::UnitedKingdom(QuantLib::UnitedKingdom::Settlement),
                                    QuantLib::JoinHolidays)) ;

        createCalendar.registerType("AUD LIBOR", new QuantLib::JointCalendar(
                                    QuantLib::Australia(),
                                    QuantLib::UnitedKingdom(QuantLib::UnitedKingdom::Settlement),
                                    QuantLib::JoinHolidays)) ;

    }