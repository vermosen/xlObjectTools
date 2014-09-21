/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSchurEigenVector(const XLOPER & xDll) {

        // register the function xlSchurEigenVector
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlSchurEigenVector"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x25""SCHUR.EIGEN.VECTOR"),
            TempStrNoSize("\x19""matrix identifier,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3D""This function provide the Schur decomposition's eigen vectors"),
            TempStrNoSize("\x17""The matrix to decompose"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

    }

inline void unregisterxlSchurEigenVector(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// release the function xlSchurEigenVector
		Excel(xlfRegister, 0, 12, &xDll,
			TempStrNoSize("\x12""xlSchurEigenVector"),
			TempStrNoSize("\x04""PCP#"),
			TempStrNoSize("\x25""SCHUR.EIGEN.VECTOR"),
			TempStrNoSize("\x19""matrix identifier,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Math"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x3D""This function provide the Schur decomposition's eigen vectors"),
			TempStrNoSize("\x17""The matrix to decompose"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlSchurEigenVector")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }