/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlMeanEWMA(const XLOPER & xDll) {

             // Enregistre la fonction xlMeanEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0A""xlMeanEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0C""MOYENNE.EWMA"),
            TempStrNoSize("\x41""série à estimer,facteur d'obsolescence,date de la moyenne,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x77""Cette fonction calcule la moyenne d'une série pour une valeur du facteur d'obsolescence donnée et une date d'évaluation"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x21""La date d'évalation de la moyenne"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlMeanEWMA(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlMeanEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0A""xlMeanEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0C""MOYENNE.EWMA"),
            TempStrNoSize("\x41""série à estimer,facteur d'obsolescence,date de la moyenne,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x77""Cette fonction calcule la moyenne d'une série pour une valeur du facteur d'obsolescence donnée et une date d'évaluation"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x21""La date d'évalation de la moyenne"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0A""xlMeanEWMA")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }