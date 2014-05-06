/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositBootstrapHelper2(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDepositBootstrapHelper2
        Excel(xlfRegister, 0, 17, & xDll,
              TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2"),
              TempStrNoSize("\x09""PCCPPEPP#"),
              TempStrNoSize("\x1C""OBJECT.CURVE.HELPER.DEPOSIT2"),
              TempStrNoSize("\x50""object Id,maturity,calendar,settlement days,deposit rates,daycount basis,trigger"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x17""xlObjectTools - Object"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x3F""This function creates a deposit helper for yield curve building"),
              TempStrNoSize("\x0D""The object Id"),
              TempStrNoSize("\x1C""Maturity date of the deposit"),
			  TempStrNoSize("\x12""Reference calendar"),
			  TempStrNoSize("\x21""Number of business days to settle"),
              TempStrNoSize("\x0C""Deposit rate"),
			  TempStrNoSize("\x0E""Daycount basis"),
              TempStrNoSize("\x09""trigger  "));

    }

inline void unregisterxlInitiateDepositBootstrapHelper2(const XLOPER & xDll) {

        XLOPER xlRegID;

             // supprime la fonction xlInitiateDepositBootstrapHelper2
		Excel(xlfRegister, 0, 17, &xDll,
			TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2"),
			TempStrNoSize("\x09""PCCPPEPP#"),
			TempStrNoSize("\x1C""OBJECT.CURVE.HELPER.DEPOSIT2"),
			TempStrNoSize("\x50""object Id,maturity,calendar,settlement days,deposit rates,daycount basis,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x17""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x3F""This function creates a deposit helper for yield curve building"),
			TempStrNoSize("\x0D""The object Id"),
			TempStrNoSize("\x1C""Maturity date of the deposit"),
			TempStrNoSize("\x12""Reference calendar"),
			TempStrNoSize("\x21""Number of business days to settle"),
			TempStrNoSize("\x0C""Deposit rate"),
			TempStrNoSize("\x0E""Daycount basis"),
			TempStrNoSize("\x09""trigger  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID);

    }
