/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentSettlementDate(const XLOPER & xDll) {

             // Enregistre la fonction xlTNoteTheoreticalPrice
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1A""xlInstrumentSettlementDate"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x19""INSTRUMENT.DATE.REGLEMENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date d'évaluation,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3B""Cette fonction calcule la date de règlement de l'instrument"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x14""La date d'évaluation"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentSettlementDate(const XLOPER & xDll) {

        XLOPER xlRegID ;

        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x1A""xlInstrumentSettlementDate"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x19""INSTRUMENT.DATE.REGLEMENT"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date d'évaluation,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3B""Cette fonction calcule la date de règlement de l'instrument"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x14""La date d'évaluation"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1A""xlInstrumentSettlementDate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }