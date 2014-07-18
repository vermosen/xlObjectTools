/*
*  xlObjectTools
*
*  Created by Jean-Matthieu VERMOSEN on 31/05/09
*  Copyright 2009. All rights reserved.
*
*/

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlRetrieveError(const XLOPER & xDll) {

	// register the function xlRetriveError
	Excel(xlfRegister, 0, 12, &xDll,
		TempStrNoSize("\x0F""xlRetrieveError"),
		TempStrNoSize("\x04""PPP#"),
		TempStrNoSize("\x14""ADDIN.RETRIEVE.ERROR"),
		TempStrNoSize("\x0D""range,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x15""xlObjectTools - addin"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x47""This function retrieves the current error associated with a given range"),
		TempStrNoSize("\x1A""The error generating range"),
		TempStrNoSize("\x07""trigger"));

}

inline void unregisterxlRetrieveError(const XLOPER & xDll) {

	XLOPER xlRegID;

	// register the function xlRetriveError
	Excel(xlfRegister, 0, 12, &xDll,
		TempStrNoSize("\x0F""xlRetrieveError"),
		TempStrNoSize("\x04""PPP#"),
		TempStrNoSize("\x14""ADDIN.RETRIEVE.ERROR"),
		TempStrNoSize("\x0D""range,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x15""xlObjectTools - addin"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x47""This function retrieves the current error associated with a given range"),
		TempStrNoSize("\x1A""The error generating range"),
		TempStrNoSize("\x07""trigger"));

	Excel4(xlfRegisterId, &xlRegID, 2, &xDll,
		TempStrNoSize("\x0F""xlRetrieveError"));

	Excel4(xlfUnregister, 0, 1, &xlRegID);

}