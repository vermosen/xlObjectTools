/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "register_compounding.hpp"

void registerCompounding() {

        ObjectHandler::compoundingFactory createCompounding ;

        createCompounding.registerType("Simple", new QuantLib::Compounding(QuantLib::Simple)) ;
        createCompounding.registerType("Discounted", new QuantLib::Compounding(QuantLib::Discounted)) ;
        createCompounding.registerType("Compounded", new QuantLib::Compounding(QuantLib::Compounded)) ;
        createCompounding.registerType("Continuous", new QuantLib::Compounding(QuantLib::Continuous)) ;
        createCompounding.registerType("SimpleThenCompounded", new QuantLib::Compounding(QuantLib::SimpleThenCompounded)) ;
        createCompounding.registerType("australiaCompounded", new QuantLib::Compounding(QuantLib::australiaCompounded)) ;

    } ;