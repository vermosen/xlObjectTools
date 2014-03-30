/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapConvexity(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapAccruedAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x19""xlSwapConvexity"),
            TempStrNoSize("\x05""PCEP#"),
            TempStrNoSize("\x19""SWAP.CONVEXITE"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction détermine le montant couru d'une jambe ou d'un swap pour une date de règlement donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapConvexity(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // libère la fonction xlSwapAccruedAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x19""xlSwapConvexity"),
            TempStrNoSize("\x05""PCEP#"),
            TempStrNoSize("\x19""SWAP.CONVEXITE"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction détermine le montant couru d'une jambe ou d'un swap pour une date de règlement donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x19""xlSwapConvexity")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }