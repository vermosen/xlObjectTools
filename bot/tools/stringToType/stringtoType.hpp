/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef string_to_type_hpp
#define string_to_type_hpp

template <typename T> void stringtoType (const std::string & str, T & dest) {

        std::istringstream iss(str) ;
        iss >> dest ;

    }

#endif
