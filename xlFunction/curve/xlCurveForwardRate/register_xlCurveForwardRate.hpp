/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCurveForwardRate(const XLOPER & xDll) {

             // Enregistre la fonction xlCurveForwardRate
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x12""xlCurveForwardRate"),
            TempStrNoSize("\x07""BCEECP#"),
            TempStrNoSize("\x13""COURBE.TAUX.FORWARD"),
            TempStrNoSize("\x31""Identifiant de la courbe,t1,t2,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3B""Cette fonction extrait le taux forward de la courbe pointée"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x2A""La date de positionnement de l'observation"),
            TempStrNoSize("\x26""La date de terminaison du taux forward"),
            TempStrNoSize("\x29""L'indentifiant de la convention de calcul"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlCurveForwardRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlCurveForwardRate
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x12""xlCurveForwardRate"),
            TempStrNoSize("\x07""BCEECP#"),
            TempStrNoSize("\x13""COURBE.TAUX.FORWARD"),
            TempStrNoSize("\x31""Identifiant de la courbe,t1,t2,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3B""Cette fonction extrait le taux forward de la courbe pointée"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x2A""La date de positionnement de l'observation"),
            TempStrNoSize("\x26""La date de terminaison du taux forward"),
            TempStrNoSize("\x29""L'indentifiant de la convention de calcul"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlCurveForwardRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }