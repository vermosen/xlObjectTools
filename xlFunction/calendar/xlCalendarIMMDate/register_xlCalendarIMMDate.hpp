/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarIMMDate(const XLOPER & xDll) {

            // Enregistre la fonction xlImmDate
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x11""xlCalendarIMMDate"),
            TempStrNoSize("\x04""BPC#"),
            TempStrNoSize("\x13""CALENDRIER.DATE.IMM"),
            TempStrNoSize("\x17""Date de départ,code IMM"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule la date correspondant au code IMM"),
            TempStrNoSize("\x11""La date de départ"),
            TempStrNoSize("\x0D""La date IMM  ")) ;

    }

inline void unregisterxlCalendarIMMDate(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // Enregistre la fonction xlImmDate
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x11""xlCalendarIMMDate"),
            TempStrNoSize("\x04""BPC#"),
            TempStrNoSize("\x13""CALENDRIER.DATE.IMM"),
            TempStrNoSize("\x17""Date de départ,code IMM"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x19""xlObjectTools - Calendar"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x38""Cette fonction calcule la date correspondant au code IMM"),
            TempStrNoSize("\x11""La date de départ"),
            TempStrNoSize("\x0D""La date IMM  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x11""xlCalendarIMMDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }