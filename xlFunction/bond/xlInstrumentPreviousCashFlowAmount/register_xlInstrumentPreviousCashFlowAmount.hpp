/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentPreviousCashFlowAmount(const XLOPER & xDll) {


             // Enregistre la fonction registerxlInstrumentPreviousCashFlowAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x22""xlInstrumentPreviousCashFlowAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x25""INSTRUMENT.MONTANT.CASHFLOW.PRECEDENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la valeur du cashflow précédent"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInstrumentPreviousCashFlowAmount(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // libère la fonction registerxlInstrumentPreviousCashFlowAmount
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x22""xlInstrumentPreviousCashFlowAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x25""INSTRUMENT.MONTANT.CASHFLOW.PRECEDENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction calcule la valeur du cashflow précédent"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x14""La date de règlement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x22""xlInstrumentPreviousCashFlowAmount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }