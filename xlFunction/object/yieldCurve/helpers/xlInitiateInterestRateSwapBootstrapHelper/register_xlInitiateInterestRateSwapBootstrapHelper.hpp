/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateInterestRateSwapBootstrapHelper(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateInterestRateSwapBootstrapHelper
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x29""xlInitiateInterestRateSwapBootstrapHelper"),
            TempStrNoSize("\x07""PCCEPP#"),
            TempStrNoSize("\x1B""INSTANCE.INTERPOLATION.SWAP"),
            TempStrNoSize("\x45""Identifiant de l'objet,Identifiant du swap,taux,courbe de discount,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x41""Cette fonction qualifie un swap pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x15""L'identifiant du swap"),
            TempStrNoSize("\x13""La cotation du swap"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'actualisation"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateInterestRateSwapBootstrapHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateInterestRateSwapBootstrapHelper
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x29""xlInitiateInterestRateSwapBootstrapHelper"),
            TempStrNoSize("\x07""PCCEPP#"),
            TempStrNoSize("\x1B""INSTANCE.INTERPOLATION.SWAP"),
            TempStrNoSize("\x45""Identifiant de l'objet,Identifiant du swap,taux,courbe de discount,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x41""Cette fonction qualifie un swap pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x15""L'identifiant du swap"),
            TempStrNoSize("\x13""La cotation du swap"),
            TempStrNoSize("\x2A""L'identifiant de la courbe d'actualisation"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x29""xlInitiateInterestRateSwapBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }