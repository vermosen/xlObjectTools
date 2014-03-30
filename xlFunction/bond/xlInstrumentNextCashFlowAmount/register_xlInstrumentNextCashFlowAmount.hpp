/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentNextCashFlowAmount(const XLOPER & xDll) {


             // Enregistre la fonction registerxlInstrumentPreviousCashFlowAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1E""xlInstrumentNextCashFlowAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x23""INSTRUMENT.MONTANT.CASHFLOW.SUIVANT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la valeur du cashflow suivant"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInstrumentNextCashFlowAmount(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction registerxlInstrumentPreviousCashFlowAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1E""xlInstrumentNextCashFlowAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x23""INSTRUMENT.MONTANT.CASHFLOW.SUIVANT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la valeur du cashflow suivant"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1E""xlInstrumentNextCashFlowAmount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }