/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateBondBootstrapHelper(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateBondBootstrapHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1D""xlInitiateBondBootstrapHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1B""INSTANCE.INTERPOLATION.BOND"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du titre,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un titre pour l'interpolation d'une courbe"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x16""L'identifiant du titre"),
            TempStrNoSize("\x10""Le prix du titre"),
            TempStrNoSize("\x09""trigger  ")) ;

    }

inline void unregisterxlInitiateBondBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateBondBootstrapHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1D""xlInitiateBondBootstrapHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1B""INSTANCE.INTERPOLATION.BOND"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du titre,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un titre pour l'interpolation d'une courbe"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x16""L'identifiant du titre"),
            TempStrNoSize("\x10""Le prix du titre"),
            TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1D""xlInitiateBondBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }