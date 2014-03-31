/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 30/10/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/factory/constraint/register_constraint.hpp>

void registerConstraint() {


        ObjectHandler::constraintFactory createConstraint ;

        createConstraint.registerType("No Constraint", new QuantLib::NoConstraint()) ;
        createConstraint.registerType("Positive Constraint", new QuantLib::PositiveConstraint()) ;
        createConstraint.registerType("NSS Constraint", new QuantLib::stochasticSvenssonConstraint()) ;


    }