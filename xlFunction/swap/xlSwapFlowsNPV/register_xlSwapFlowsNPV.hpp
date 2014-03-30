/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 17/01/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSwapFlowsNPV(const XLOPER & xDll) {

             // Enregistre la fonction xlSwapFlowsNPV
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x0E""xlSwapFlowsNPV"),
            TempStrNoSize("\x05""PCCP#"),
            TempStrNoSize("\x0D""SWAP.FLUX.NPV"),
            TempStrNoSize("\x40""Identifiant de l'instrument,identifiant de la courbe,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3A""Cette fonction calcule la NPV des flux d'une jambe de swap"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1A""L'identifiant de la courbe"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlSwapFlowsNPV(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlSwapFlowsNPV
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x0E""xlSwapFlowsNPV"),
            TempStrNoSize("\x05""PCCP#"),
            TempStrNoSize("\x0D""SWAP.FLUX.NPV"),
            TempStrNoSize("\x40""Identifiant de l'instrument,identifiant de la courbe,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Swap"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3A""Cette fonction calcule la NPV des flux d'une jambe de swap"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1A""L'identifiant de la courbe"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0E""xlSwapFlowsNPV")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }