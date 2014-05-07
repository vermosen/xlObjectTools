/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositFutureBootstrapHelper(const XLOPER & xDll) {


             // Enregistre la fonction xlInitiateDepositFutureBootstrapHelper
        Excel(xlfRegister, 0, 17, & xDll,
            TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper"),
            TempStrNoSize("\x09""PCCCEPPP#"),
            TempStrNoSize("\x1A""OBJECT.CURVE.HELPER.FUTURE"),
            TempStrNoSize("\x5E""Identifiant de l'objet,Code IMM,Index,Prix,Ajustement en convexité,Retour à la moyenne,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3B""Cette fonction instancie un helper pour un future sur dépot"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
			TempStrNoSize("\x23""Le code IMM correspondant au future"),
            TempStrNoSize("\x18""L'identifiant de l'index"),
			TempStrNoSize("\x11""Le prix du future"),
            TempStrNoSize("\x19""L'ajustement en convexité"),
			TempStrNoSize("\x21""le facteur de retour à la moyenne"),
            TempStrNoSize("\x09""trigger  ")) ;


    }

inline void unregisterxlInitiateDepositFutureBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateDepositFutureBootstrapHelper
		Excel(xlfRegister, 0, 17, &xDll,
			TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper"),
			TempStrNoSize("\x09""PCCCEPPP#"),
			TempStrNoSize("\x1A""OBJECT.CURVE.HELPER.FUTURE"),
			TempStrNoSize("\x5E""Identifiant de l'objet,Code IMM,Index,Prix,Ajustement en convexité,Retour à la moyenne,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x17""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x3B""Cette fonction instancie un helper pour un future sur dépot"),
			TempStrNoSize("\x19""L'identifiant de l'object"),
			TempStrNoSize("\x23""Le code IMM correspondant au future"),
			TempStrNoSize("\x18""L'identifiant de l'index"),
			TempStrNoSize("\x11""Le prix du future"),
			TempStrNoSize("\x19""L'ajustement en convexité"),
			TempStrNoSize("\x21""le facteur de retour à la moyenne"),
			TempStrNoSize("\x09""trigger  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x26""xlInitiateDepositFutureBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }