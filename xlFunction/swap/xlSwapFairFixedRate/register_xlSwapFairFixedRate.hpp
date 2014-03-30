/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapFairFixedRate(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapFairFixedRate
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x13""xlSwapFairFixedRate"),
            TempStrNoSize("\x06""PCCCP#"),
            TempStrNoSize("\x19""SWAP.TAUX.FIXE.EQUIVALENT"),
            TempStrNoSize("\x58""Identifiant de l'instrument,Identifiant de la jambe,Identifiant de la courbe,Déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule le taux fixe equivalent d'un Swap"),
            TempStrNoSize("\x15""L'identifiant du Swap"),
            TempStrNoSize("\x28""L'identifiant de la jambe fixe à ajuster"),
            TempStrNoSize("\x16""La courbe de référence"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapFairFixedRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlSwapFairFixedRate
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x13""xlSwapFairFixedRate"),
            TempStrNoSize("\x06""PCCCP#"),
            TempStrNoSize("\x19""SWAP.TAUX.FIXE.EQUIVALENT"),
            TempStrNoSize("\x58""Identifiant de l'instrument,Identifiant de la jambe,Identifiant de la courbe,Déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule le taux fixe equivalent d'un Swap"),
            TempStrNoSize("\x15""L'identifiant du Swap"),
            TempStrNoSize("\x28""L'identifiant de la jambe fixe à ajuster"),
            TempStrNoSize("\x16""La courbe de référence"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x13""xlSwapFairFixedRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }