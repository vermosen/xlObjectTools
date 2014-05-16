/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateOvernightIndexedBootstrapHelper(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDepositBootstrapHelper
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper"),
            TempStrNoSize("\x07""PCCEEP#"),
            TempStrNoSize("\x25""INSTANCE.INTERPOLATION.SWAP.OVERNIGHT"),
            TempStrNoSize("\x43""Identifiant de l'objet,Identifiant de l'index,maturité,taux,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x46""Cette fonction instancie un swap OIS pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x18""L'identifiant de l'index"),
			TempStrNoSize("\x1B""La date de maturité du swap"),
            TempStrNoSize("\x0F""Le taux du swap"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;


    }

inline void unregisterxlInitiateOvernightIndexedBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateDepositBootstrapHelper
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper"),
            TempStrNoSize("\x07""PCCEEP#"),
            TempStrNoSize("\x25""INSTANCE.INTERPOLATION.SWAP.OVERNIGHT"),
            TempStrNoSize("\x43""Identifiant de l'objet,Identifiant de l'index,maturité,taux,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x46""Cette fonction instancie un swap OIS pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x18""L'identifiant de l'index"),
			TempStrNoSize("\x1B""La date de maturité du swap"),
            TempStrNoSize("\x0F""Le taux du swap"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x29""xlInitiateOvernightIndexedBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }