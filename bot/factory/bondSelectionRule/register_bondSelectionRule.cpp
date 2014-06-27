/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/bondSelectionRule/register_bondSelectionRule.hpp>


void registerBondSelectionRule() {

        ObjectHandler::bondSelectionRuleFactory createBondSelectionRule ;

        createBondSelectionRule.registerType("active Rule"        , new QuantLib::activeRule()     );
        createBondSelectionRule.registerType("on-the-run 10 Rule" , new QuantLib::onTheRun10Rule() );
		createBondSelectionRule.registerType("on-the-run 30 Rule" , new QuantLib::onTheRun30Rule() );
		createBondSelectionRule.registerType("off-the-run 10 Rule", new QuantLib::offTheRun10Rule());

    }