/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentNextCashFlowDate(const XLOPER & xDll) {


             // Enregistre la fonction xlNextCashFlowDate
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1C""xlInstrumentNextCashFlowDate"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x20""INSTRUMENT.DATE.CASHFLOW.SUIVANT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x33""Cette fonction calcule la date de cashflow suivante"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInstrumentNextCashFlowDate(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction xlInstrumentNextCashFlowDate
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1C""xlInstrumentNextCashFlowDate"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x20""INSTRUMENT.DATE.CASHFLOW.SUIVANT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x33""Cette fonction calcule la date de cashflow suivante"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1C""xlInstrumentNextCashFlowDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }