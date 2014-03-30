/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */


#include <bot/factory/businessDayConvention/register_businessDayConvention.hpp>

void registerBusinessDayConvention() {

        ObjectHandler::businessDayConventionFactory createBusinessDayConvention ;

        createBusinessDayConvention.registerType("Following", new QuantLib::BusinessDayConvention(QuantLib::Following)) ;
        createBusinessDayConvention.registerType("Modified Following", new QuantLib::BusinessDayConvention(QuantLib::ModifiedFollowing)) ;
        createBusinessDayConvention.registerType("Modified Preceding", new QuantLib::BusinessDayConvention(QuantLib::ModifiedPreceding)) ;
        createBusinessDayConvention.registerType("Unadjusted", new QuantLib::BusinessDayConvention(QuantLib::Unadjusted)) ;
        createBusinessDayConvention.registerType("Preceding", new QuantLib::BusinessDayConvention(QuantLib::Preceding)) ;

    }