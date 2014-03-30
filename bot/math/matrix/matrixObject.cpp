/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include "bot/math/matrix/matrixObject.hpp"

namespace QuantLibAddin {

    matrixObject::matrixObject(const boost::shared_ptr<QuantLibAddin::ValueObjects::matrixValueObject> & valueObject,
		const QuantLib::Matrix & matrix,
        const bool & permanent) : 

        ObjectHandler::LibraryObject<QuantLib::Matrix>(valueObject, permanent) {        

            libraryObject_ = boost::shared_ptr<QuantLib::Matrix> (new
                QuantLib::Matrix(matrix)) ;

    } ;
     
}