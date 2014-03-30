/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarDaycount(const XLOPER & xDll) {

            // Enregistre la fonction xlDaycount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x12""xlCalendarDaycount"),
            TempStrNoSize("\x05""BEEC#"),
            TempStrNoSize("\x15""CALENDRIER.FRAC.ANNEE"),
            TempStrNoSize("\x28""Date de départ,Date de fin,Base annuelle"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction calcule la fraction d'année corespondant à un intervalle de dates pour une convention"),
            TempStrNoSize("\x11""La date de départ"),
            TempStrNoSize("\x0E""La date de fin"),
            TempStrNoSize("\x12""La base annuelle  ")) ;

    }

inline void unregisterxlCalendarDaycount(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // Enregistre la fonction xlDaycount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x12""xlCalendarDaycount"),
            TempStrNoSize("\x05""BEEC#"),
            TempStrNoSize("\x15""CALENDRIER.FRAC.ANNEE"),
            TempStrNoSize("\x28""Date de départ,Date de fin,Base annuelle"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x64""Cette fonction calcule la fraction d'année corespondant à un intervalle de dates pour une convention"),
            TempStrNoSize("\x11""La date de départ"),
            TempStrNoSize("\x0E""La date de fin"),
            TempStrNoSize("\x12""La base annuelle  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlCalendarDaycount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }