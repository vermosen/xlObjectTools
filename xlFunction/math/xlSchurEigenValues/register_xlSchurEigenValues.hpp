/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSchurEigenValues(const XLOPER & xDll) {

        // register the function xlSchurEigenValues
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlSchurEigenValues"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x13""SCHUR.DECOMPOSITION"),
            TempStrNoSize("\x19""matrix identifier,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""This function provide Schur decomposition's eigen values"),
            TempStrNoSize("\x11""Matrix identifier"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

    }

inline void unregisterxlSchurEigenValues(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// register the function xlSchurEigenValues
		Excel(xlfRegister, 0, 12, &xDll,
			TempStrNoSize("\x12""xlSchurEigenValues"),
			TempStrNoSize("\x04""PCP#"),
			TempStrNoSize("\x13""SCHUR.DECOMPOSITION"),
			TempStrNoSize("\x19""matrix identifier,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x15""xlObjectTools - Math"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x38""This function provide Schur decomposition's eigen values"),
			TempStrNoSize("\x11""Matrix identifier"),
			TempStrNoSize("\x25""Triggers the computation (optional)  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0B""xlSchurForm"));

        Excel4(xlfUnregister, 0, 1, & xlRegID);

    }
