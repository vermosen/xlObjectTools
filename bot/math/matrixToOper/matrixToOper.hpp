/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_matrix_to_oper_hpp
#define bot_matrix_to_oper_hpp

#include <ohxl/conversions/scalartooper.hpp>

//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/vector.hpp>

#include <ql/math/matrix.hpp>
#include <ql/math/array.hpp>

namespace ObjectHandler {

	void MatrixToOper(QuantLib::Matrix & vv,
		OPER & xMatrix,
		bool dllToFree = true);

	void VectorToOper(const QuantLib::Array & vv,
		OPER & xMatrix,
		bool dllToFree = true);

}

#endif