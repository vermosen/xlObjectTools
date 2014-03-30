/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlVolatilityEWMA(const XLOPER & xDll) {

             // Enregistre la fonction xlVolatilityEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x10""xlVolatilityEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0F""VOLATILITE.EWMA"),
            TempStrNoSize("\x40""série à estimer,facteur d'obsolescence,date d'évaluation,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x68""Cette fonction calcule la volatilité simple d'une série pour une valeur du facteur d'obsolescence donnée"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x25""La date d'évaluation de la volatilité"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlVolatilityEWMA(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlVolatilityEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x10""xlVolatilityEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0F""VOLATILITE.EWMA"),
            TempStrNoSize("\x40""série à estimer,facteur d'obsolescence,date d'évaluation,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x68""Cette fonction calcule la volatilité simple d'une série pour une valeur du facteur d'obsolescence donnée"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x25""La date d'évaluation de la volatilité"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x10""xlVolatilityEWMA")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }