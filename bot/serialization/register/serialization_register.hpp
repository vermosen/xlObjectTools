/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/serialization/register/serialization_all.hpp>

namespace QuantLibAddin {

        template<class Archive>
        void tpl_register_classes(Archive & ar) {


                    // Leg
                register_leg(ar) ;


            }

    }

