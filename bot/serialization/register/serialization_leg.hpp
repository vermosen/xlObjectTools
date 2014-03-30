/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_serialization_leg_hpp
#define bot_serialization_leg_hpp

#include <boost/archive/xml_iarchive.hpp>

#include <boost/archive/xml_oarchive.hpp>

namespace QuantLibAddin {


        void register_leg(boost::archive::xml_oarchive & ar) ;

        void register_leg(boost::archive::xml_iarchive & ar) ;
        

    }

#endif

