/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositBootstrapHelper(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDepositBootstrapHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x20""xlInitiateDepositBootstrapHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1C""INSTANCE.INTERPOLATION.DEPOT"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du dépot,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un dépôt pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x16""L'identifiant du dépot"),
            TempStrNoSize("\x10""Le prix du dépôt"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateDepositBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateDepositBootstrapHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x20""xlInitiateDepositBootstrapHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1C""INSTANCE.INTERPOLATION.DEPOT"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du dépot,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un dépôt pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x16""L'identifiant du dépot"),
            TempStrNoSize("\x10""Le prix du dépôt"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x20""xlInitiateDepositBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }