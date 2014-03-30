/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCurveReferenceDate(const XLOPER & xDll) {

             // Enregistre la fonction xlCurveSettlementDate
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x14""xlCurveReferenceDate"),
            TempStrNoSize("\x04""BCP#"),
            TempStrNoSize("\x15""COURBE.DATE.REFERENCE"),
            TempStrNoSize("\x24""Identifiant de la courbe,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule la date de référence d'une courbe"),
            TempStrNoSize("\x13""Le nom de la courbe"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlCurveReferenceDate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlCurveSettlementDate
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x14""xlCurveReferenceDate"),
            TempStrNoSize("\x04""BCP#"),
            TempStrNoSize("\x15""COURBE.DATE.REFERENCE"),
            TempStrNoSize("\x24""Identifiant de la courbe,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule la date de référence d'une courbe"),
            TempStrNoSize("\x13""Le nom de la courbe"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x14""xlCurveReferenceDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }