/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlZScoreEWMA(const XLOPER & xDll) {

             // Enregistre la fonction xlZScoreEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0C""xlZScoreEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0C""Z.SCORE.EWMA"),
            TempStrNoSize("\x40""série à estimer,facteur d'obsolescence,date d'évaluation,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5E""Cette fonction calcule le z-score d'une série pour une valeur du facteur d'obsolescence donnée"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x1F""La date d'évaluation du z-score"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlZScoreEWMA(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlZScoreEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0C""xlZScoreEWMA"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x0C""Z.SCORE.EWMA"),
            TempStrNoSize("\x40""série à estimer,facteur d'obsolescence,date d'évaluation,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5E""Cette fonction calcule le z-score d'une série pour une valeur du facteur d'obsolescence donnée"),
            TempStrNoSize("\x21""Identifiant de la série à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x1F""La date d'évaluation du z-score"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0C""xlZScoreEWMA")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }