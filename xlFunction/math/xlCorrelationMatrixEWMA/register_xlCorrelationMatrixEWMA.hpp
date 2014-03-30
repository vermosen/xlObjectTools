/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCorrelationMatrixEWMA(const XLOPER & xDll) {

             // Enregistre la fonction xlCorrelationMatrixEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x17""xlCorrelationMatrixEWMA"),
            TempStrNoSize("\x07""PPEELP#"),
            TempStrNoSize("\x18""MATRICE.CORRELATION.EWMA"),
            TempStrNoSize("\x56""plage des séries,facteur d'obsolescence, date d'évaluation,indicateur de norme,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x93""Cette fonction calcule la matrice des correlation d'un ensemble de séries pour une valeur du facteur d'obsolescence et une date d'évaluation donnée"),
            TempStrNoSize("\x2E""La plage des identifiants des séries à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x29""Indique si la volatilité doit être normée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlCorrelationMatrixEWMA(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlCovarianceMatrixEWMA
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x17""xlCorrelationMatrixEWMA"),
            TempStrNoSize("\x07""PPEELP#"),
            TempStrNoSize("\x18""MATRICE.CORRELATION.EWMA"),
            TempStrNoSize("\x56""plage des séries,facteur d'obsolescence, date d'évaluation,indicateur de norme,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x93""Cette fonction calcule la matrice des correlation d'un ensemble de séries pour une valeur du facteur d'obsolescence et une date d'évaluation donnée"),
            TempStrNoSize("\x2E""La plage des identifiants des séries à estimer"),
            TempStrNoSize("\x25""La valeur du paramètre d'obsolescence"),
            TempStrNoSize("\x29""Indique si la volatilité doit être normée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x17""xlCorrelationMatrixEWMA")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }