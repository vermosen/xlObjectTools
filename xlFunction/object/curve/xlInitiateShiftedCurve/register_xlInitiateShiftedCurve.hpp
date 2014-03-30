/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 09/05/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateShiftedCurve(const XLOPER & xDll) {

             // Enregistre la fonction registerxlShiftedCurve
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0E""xlShiftedCurve"),
            TempStrNoSize("\x06""CCCCP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.SHIFTEE"),
            TempStrNoSize("\x2B""courbe shiftée,courbe de base,shift,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction applique le shift à la courbe de base"),
            TempStrNoSize("\x22""L'identifiant de la courbe shiftée"),
            TempStrNoSize("\x24""L'identifiant de la courbe de base"),
            TempStrNoSize("\x26""L'identifiant de la structure de shift"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateShiftedCurve(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction registerxlShiftedCurve
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x0E""xlShiftedCurve"),
            TempStrNoSize("\x06""CCCCP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.SHIFTEE"),
            TempStrNoSize("\x2B""courbe shiftée,courbe de base,shift,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction applique le shift à la courbe de base"),
            TempStrNoSize("\x22""L'identifiant de la courbe shiftée"),
            TempStrNoSize("\x24""L'identifiant de la courbe de base"),
            TempStrNoSize("\x26""L'identifiant de la structure de shift"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x16""registerxlShiftedCurve")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }