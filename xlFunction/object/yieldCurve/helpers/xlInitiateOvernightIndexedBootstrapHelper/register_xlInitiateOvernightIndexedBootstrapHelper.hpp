/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateOvernightIndexedBootstrapHelper(const XLOPER & xDll) {

    // register the xlInitiateDepositBootstrapHelper function
	Excel(xlfRegister, 0, 15, &xDll,
		TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper"),
		TempStrNoSize("\x07""PCCEEP#"),
		TempStrNoSize("\x22""OBJECT.CURVE.HELPER.OVERNIGHT.SWAP"),
		TempStrNoSize("\x39""object indentifier,index identifier,maturity,rate,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x40""This function creates an OIS swap helper for curve bootstrapping"),
		TempStrNoSize("\x11""Object Identifier"),
		TempStrNoSize("\x11""Index indentifier"),
		TempStrNoSize("\x19""Maturity date of the swap"),
		TempStrNoSize("\x16""Fixed rate of the swap"),
		TempStrNoSize("\x19""Trigger for recalculation"));

    }

inline void unregisterxlInitiateOvernightIndexedBootstrapHelper(const XLOPER & xDll) {

    XLOPER xlRegID ;

	// unregister the xlInitiateDepositBootstrapHelper function
	Excel(xlfRegister, 0, 15, &xDll,
		TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper"),
		TempStrNoSize("\x07""PCCEEP#"),
		TempStrNoSize("\x22""OBJECT.CURVE.HELPER.OVERNIGHT.SWAP"),
		TempStrNoSize("\x39""object indentifier,index identifier,maturity,rate,trigger"),
		TempStrNoSize("\x01""1"),
		TempStrNoSize("\x16""xlObjectTools - Object"),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x00"""),
		TempStrNoSize("\x40""This function creates an OIS swap helper for curve bootstrapping"),
		TempStrNoSize("\x11""Object Identifier"),
		TempStrNoSize("\x11""Index indentifier"),
		TempStrNoSize("\x19""Maturity date of the swap"),
		TempStrNoSize("\x16""Fixed rate of the swap"),
		TempStrNoSize("\x19""Trigger for recalculation"));

    Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
        TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper")) ;

    Excel4(xlfUnregister, 0, 1, & xlRegID) ;

}