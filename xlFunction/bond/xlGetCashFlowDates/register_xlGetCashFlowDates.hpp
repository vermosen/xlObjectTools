/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlGetCashFlowDates(const XLOPER & xDll) {


             // Enregistre la fonction xlRecoverNSSParameters
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlGetCashFlowDates"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x19""INSTRUMENT.DATES.CASHFLOW"),
            TempStrNoSize("\x27""Identifiant de l'instrument,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x39""Cette fonction affiche les dates des flux de l'instrument"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlGetCashFlowDates(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction xlRecoverNSSParameters
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlGetCashFlowDates"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x19""INSTRUMENT.DATES.CASHFLOW"),
            TempStrNoSize("\x27""Identifiant de l'instrument,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x39""Cette fonction affiche les dates des flux de l'instrument"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlGetCashFlowDates")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }