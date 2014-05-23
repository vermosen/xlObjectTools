/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositFutureBootstrapHelper(const XLOPER & xDll) {

    // register the function xlInitiateDepositFutureBootstrapHelper
    Excel(xlfRegister, 0, 17, & xDll,
        TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper"),
        TempStrNoSize("\x09""PCCCEPPP#"),
        TempStrNoSize("\x1A""OBJECT.CURVE.HELPER.FUTURE"),
        TempStrNoSize("\x4A""Object Id,IMM code,Index,Price,Convexity adjustment,Mean Reverting,Trigger"),
        TempStrNoSize("\x01""1"),
        TempStrNoSize("\x17""xlObjectTools - Object"),
        TempStrNoSize("\x00"""),
        TempStrNoSize("\x00"""),
        TempStrNoSize("\x2D""This function instanciate a eurodollar future"),
        TempStrNoSize("\x15""The object identifier"),
		TempStrNoSize("\x1A""The corresponding IMM code"),
        TempStrNoSize("\x1E""The reference index identifier"),
		TempStrNoSize("\x10""The future price"),
        TempStrNoSize("\x18""The convexity adjustment"),
		TempStrNoSize("\x19""The mean reverting factor"),
        TempStrNoSize("\x1F""The Trigger for recomputation  "));

}

inline void unregisterxlInitiateDepositFutureBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

	// unregister the function xlInitiateDepositFutureBootstrapHelper
	Excel(xlfRegister, 0, 17, &xDll,
		TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper"),
		TempStrNoSize("\x09""PCCCEPPP#"),
		TempStrNoSize("\x1A""OBJECT.CURVE.HELPER.FUTURE"),
		TempStrNoSize("\x4A""Object Id,IMM code,Index,Price,Convexity adjustment,Mean Reverting,Trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x17""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x2D""This function instanciate a eurodollar future"),
		TempStrNoSize("\x15""The object identifier"),
		TempStrNoSize("\x1A""The corresponding IMM code"),
		TempStrNoSize("\x1E""The reference index identifier"),
		TempStrNoSize("\x10""The future price"),
		TempStrNoSize("\x18""The convexity adjustment"),
		TempStrNoSize("\x19""The mean reverting factor"),
		TempStrNoSize("\x1F""The Trigger for recomputation  "));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper"));

    Excel4(xlfUnregister, 0, 1, & xlRegID);

}