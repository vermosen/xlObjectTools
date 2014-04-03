/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_oper_to_matrix_hpp
#define bot_oper_to_matrix_hpp

#include <ohxl\conversions/opertomatrix.hpp>

#include <ql/math/matrix.hpp>

namespace ObjectHandler {

    //! Helper template wrapper for operToMatrixImpl
    /*! Accept an OPER as input and wrap this in class ConvertOper.
        This simplifies syntax in client applications.
    */
    QuantLib::Matrix operToMatrix(
        const OPER & xMatrix,
        const std::string & paramName) {
		
		std::vector<std::vector<double> > mat = operToMatrixImpl<double>
			(ConvertOper(xMatrix, false), paramName);

		QuantLib::Matrix returnValue(mat.size(), mat[0].size(), 0.0);

		QuantLib::Size r = mat.size(), c = mat[0].size();
		for (QuantLib::Size i = 0; i < r; i++) {
		
			for (QuantLib::Size j = 0; j < c; j++)

				returnValue[i][j] = mat[i][j];

		}

		return returnValue;

	}

}

#endif

