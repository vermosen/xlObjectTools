/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_matrix_object_hpp
#define bot_matrix_object_hpp

#include <oh/libraryobject.hpp>

#include <ql/math/matrix.hpp>

#include "bot/math/matrix/matrixValueObject.hpp"

namespace QuantLibAddin {

    class matrixObject : public ObjectHandler::LibraryObject<QuantLib::Matrix> {

    public :
        matrixObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::matrixValueObject> & valueObject,
			const QuantLib::Matrix & matrix,
            const bool & permanent) ;

        } ;

    }

#endif