/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapDV01(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapAccruedAmount
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0A""xlSwapDV01"),
            TempStrNoSize("\x06""PCCCP#"),
            TempStrNoSize("\x09""SWAP.DV01"),
            TempStrNoSize("\x5D""Identifiant de l'instrument,Identifiant de la courbe,Identifiant de la convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction détermine la DV01 d'un swap ou d'une jambe pour une convention de taux donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x13""La courbe à shifter"),
            TempStrNoSize("\x1E""La convention de taux du shift"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapDV01(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // libère la fonction xlSwapAccruedAmount
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0A""xlSwapDV01"),
            TempStrNoSize("\x06""PCCCP#"),
            TempStrNoSize("\x09""SWAP.DV01"),
            TempStrNoSize("\x5D""Identifiant de l'instrument,Identifiant de la courbe,Identifiant de la convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction détermine la DV01 d'un swap ou d'une jambe pour une convention de taux donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x13""La courbe à shifter"),
            TempStrNoSize("\x1E""La convention de taux du shift"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0A""xlSwapDV01")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }