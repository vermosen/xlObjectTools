/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentAccruedAmount(const XLOPER & xDll) {

             // Enregistre la fonction xlTNoteTheoreticalPrice
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x19""xlInstrumentAccruedAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x19""INSTRUMENT.COUPON.COURU"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x36""Cette fonction calcule le coupon couru d'un instrument"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentAccruedAmount(const XLOPER & xDll) {

        XLOPER xlRegID ;

        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x19""xlInstrumentAccruedAmount"),
            TempStrNoSize("\x05""PCPP#"),
            TempStrNoSize("\x19""INSTRUMENT.COUPON.COURU"),
            TempStrNoSize("\x39""Identifiant de l'instrument,date de règlement,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x36""Cette fonction calcule le coupon couru d'un instrument"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x19""xlInstrumentAccruedAmount")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }