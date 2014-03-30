/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 17/01/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapRollDown(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapRollDown
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x0E""xlSwapRollDown"),
            TempStrNoSize("\x07""PCCPEP#"),
            TempStrNoSize("\x0E""SWAP.ROLL.DOWN"),
            TempStrNoSize("\x61""Identifiant de l'instrument,courbe d'actualisation,courbe d'extrapolation,date de fin,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x61""Cette fonction calcule le roll-down dégagé par un swap de taux pour une période de portage donnée"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'actualisation"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'extrapolation"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapRollDown(const XLOPER & xDll) {

        XLOPER xlRegID ;

			// libère la fonction xlSwapRollDown
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x0E""xlSwapRollDown"),
            TempStrNoSize("\x07""PCCPEP#"),
            TempStrNoSize("\x0E""SWAP.ROLL.DOWN"),
            TempStrNoSize("\x61""Identifiant de l'instrument,courbe d'actualisation,courbe d'extrapolation,date de fin,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x61""Cette fonction calcule le roll-down dégagé par un swap de taux pour une période de portage donnée"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'actualisation"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'extrapolation"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0E""xlSwapRollDown")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }