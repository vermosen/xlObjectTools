/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentPreviousCashFlowDate(const XLOPER & xDll) {


             // Enregistre la fonction xlInstrumentPreviousCashFlowDate
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x20""xlInstrumentPreviousCashFlowDate"),
            TempStrNoSize("\x05""PCEP#"),
            TempStrNoSize("\x22""INSTRUMENT.DATE.CASHFLOW.PRECEDENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la date de cashflow précédent"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInstrumentPreviousCashFlowDate(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction xlInstrumentNextCashFlowDate
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x20""xlInstrumentPreviousCashFlowDate"),
            TempStrNoSize("\x05""PCEP#"),
            TempStrNoSize("\x22""INSTRUMENT.DATE.CASHFLOW.PRECEDENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la date de cashflow précédent"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x20""xlInstrumentPreviousCashFlowDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }