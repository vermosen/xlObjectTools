/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCurveZeroRate(const XLOPER & xDll) {

             // Enregistre la fonction xlCurveZeroRate
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0F""xlCurveZeroRate"),
            TempStrNoSize("\x06""BCECP#"),
            TempStrNoSize("\x10""COURBE.TAUX.ZERO"),
            TempStrNoSize("\x3D""Identifiant de la courbe,date d'évaluation,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x4A""Cette fonction extrait le taux zero coupon bond basis de la courbe pointée"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x1C""La date d'évaluation du taux"),
            TempStrNoSize("\x29""L'indentifiant de la convention de calcul"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

    }

inline void unregisterxlCurveZeroRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlCurveZeroRate
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0F""xlCurveZeroRate"),
            TempStrNoSize("\x06""BCECP#"),
            TempStrNoSize("\x10""COURBE.TAUX.ZERO"),
            TempStrNoSize("\x3D""Identifiant de la courbe,date d'évaluation,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x4A""Cette fonction extrait le taux zero coupon bond basis de la courbe pointée"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x1C""La date d'évaluation du taux"),
            TempStrNoSize("\x29""L'indentifiant de la convention de calcul"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0F""xlCurveZeroRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }