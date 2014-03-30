/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "register_currency.hpp"

void registerCurrency() {

        ObjectHandler::currencyFactory createCurrency ;

        createCurrency.registerType("USD", new QuantLib::USDCurrency()) ;
        createCurrency.registerType("EUR", new QuantLib::EURCurrency()) ;
        createCurrency.registerType("GBP", new QuantLib::GBPCurrency()) ;
        createCurrency.registerType("AUD", new QuantLib::AUDCurrency()) ;

    }
