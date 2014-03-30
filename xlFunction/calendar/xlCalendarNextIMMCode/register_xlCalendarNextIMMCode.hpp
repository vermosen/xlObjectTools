/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlCalendarNextIMMCode(const XLOPER & xDll) {

            // Enregistre la fonction xlNextImmCode
        Excel(xlfRegister, 0, 11, & xDll,
              TempStrNoSize("\x15""xlCalendarNextIMMCode"),
              TempStrNoSize("\x03""CP#"),
              TempStrNoSize("\x1C""CALENDRIER.PROCHAIN.CODE.IMM"),
              TempStrNoSize("\x0E""Date de départ"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x19""xlObjectTools - Calendar"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x32""Cette fonction calcule le code IMM suivant la date"),
              TempStrNoSize("\x13""La date de départ  ")) ;

    }

inline void unregisterxlCalendarNextIMMCode(const XLOPER & xDll) {

        XLOPER xlRegID ;

            // Enregistre la fonction xlNextImmCode
        Excel(xlfRegister, 0, 11, & xDll,
              TempStrNoSize("\x15""xlCalendarNextIMMCode"),
              TempStrNoSize("\x03""CP#"),
              TempStrNoSize("\x1C""CALENDRIER.PROCHAIN.CODE.IMM"),
              TempStrNoSize("\x0E""Date de départ"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x19""xlObjectTools - Calendar"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x32""Cette fonction calcule le code IMM suivant la date"),
              TempStrNoSize("\x13""La date de départ  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
               TempStrNoSize("\x15""xlCalendarNextIMMCode")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }