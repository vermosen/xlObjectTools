/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapCurrentFixing(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapCurrentFixing
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x13""xlSwapCurrentFixing"),
            TempStrNoSize("\x06""PCEPP#"),
            TempStrNoSize("\x19""SWAP.FIXING"),
            TempStrNoSize("\x4C""Identifiant de l'instrument,date de règlement,index de référence,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction détermine le taux de fixing d'une jambe variable pour une date de règlement donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x2E""L'index des fixings de la jambe flottante"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapCurrentFixing(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // libère la fonction xlSwapAccruedAmount
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x13""xlSwapCurrentFixing"),
            TempStrNoSize("\x06""PCEPP#"),
            TempStrNoSize("\x19""SWAP.FIXING"),
            TempStrNoSize("\x4C""Identifiant de l'instrument,date de règlement,index de référence,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction détermine le taux de fixing d'une jambe variable pour une date de règlement donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x2E""L'index des fixings de la jambe flottante"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x19""xlSwapCurrentFixing")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }