/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSwapCurve(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x13""xlInitiateSwapCurve"),
            TempStrNoSize("\x07""PCPPPP#"),
            TempStrNoSize("\x14""INSTANCE.COURBE.SWAP"),
            TempStrNoSize("\x40""Identifiant de l'objet,Date de calcul,Calendrier,Helpers,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x16""La devise de la courbe"),
            TempStrNoSize("\x1B""Les helpers des instruments"),
            TempStrNoSize("\x15""déclenche le calcul  ")) ;

    }

DLLEXPORT xloper * xlInitiateSwapCurve (const char * objectID_,
                                        const xloper * calculationDate_,
                                        const xloper * curveCalendarId_,
                                        const xloper * helperId_,
                                        const xloper * trigger_) ;

inline void unregisterxlInitiateSwapCurve(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // libère la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x13""xlInitiateSwapCurve"),
            TempStrNoSize("\x07""PCPPPP#"),
            TempStrNoSize("\x14""INSTANCE.COURBE.SWAP"),
            TempStrNoSize("\x40""Identifiant de l'objet,Date de calcul,Calendrier,Helpers,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x16""La devise de la courbe"),
            TempStrNoSize("\x1B""Les helpers des instruments"),
            TempStrNoSize("\x15""déclenche le calcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x13""xlInitiateSwapCurve")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }
