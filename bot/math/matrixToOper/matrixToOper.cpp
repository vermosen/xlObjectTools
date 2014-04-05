/*
*  xlObjectTools
*
*  Created by Jean-Matthieu VERMOSEN on 18/04/10
*  Copyright 2009. All rights reserved.
*
*/

#include <bot/math/matrixToOper/matrixToOper.hpp>

namespace ObjectHandler {

	void MatrixToOper(QuantLib::Matrix & vv,
		OPER & xMatrix,
		bool dllToFree) {

		xMatrix.val.array.rows = vv.rows();
		xMatrix.val.array.columns = vv.columns();
		xMatrix.val.array.lparray = new OPER[xMatrix.val.array.rows * xMatrix.val.array.columns];

		xMatrix.xltype = xltypeMulti;

		if (dllToFree) xMatrix.xltype |= xlbitDLLFree;

		for (unsigned int i = 0; i < vv.rows(); ++i) {

			for (unsigned int j = 0; j < vv.columns(); ++j)

				scalarToOper(static_cast<double>(vv[i][j]),
				xMatrix.val.array.lparray[i * vv.columns() + j], dllToFree, false);

		}

	}

	void VectorToOper(const QuantLib::Array & vv,
		OPER & xMatrix,
		bool dllToFree) {

		xMatrix.val.array.rows = vv.size();
		xMatrix.val.array.columns = 1;
		xMatrix.val.array.lparray = new OPER[xMatrix.val.array.rows * xMatrix.val.array.columns];
		xMatrix.xltype = xltypeMulti;

		if (dllToFree) xMatrix.xltype |= xlbitDLLFree;

		for (unsigned int i = 0; i < vv.size(); ++i)

			scalarToOper(static_cast<double>(vv[i]),
			xMatrix.val.array.lparray[i], dllToFree, false);

	}

}