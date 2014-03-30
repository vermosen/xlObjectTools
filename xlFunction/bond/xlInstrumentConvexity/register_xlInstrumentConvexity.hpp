/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentConvexity(const XLOPER & xDll) {

             // Enregistre la fonction xlInstrumentDuration
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x15""xlInstrumentConvexity"),
            TempStrNoSize("\x08""PCPPECP#"),
            TempStrNoSize("\x14""INSTRUMENT.CONVEXITE"),
            TempStrNoSize("\x5B""Identifiant de l'instrument,date d'évaluation,date de règlement,prix,convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction calcule la convexité de l'instrument pour un prix et une date donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x17""La date d'évaluation"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1F""La convention de taux du calcul"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentConvexity(const XLOPER & xDll) {

        XLOPER xlRegID ;

        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x15""xlInstrumentConvexity"),
            TempStrNoSize("\x08""PCPPECP#"),
            TempStrNoSize("\x14""INSTRUMENT.CONVEXITE"),
            TempStrNoSize("\x5B""Identifiant de l'instrument,date d'évaluation,date de règlement,prix,convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction calcule la convexité de l'instrument pour un prix et une date donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x17""La date d'évaluation"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1F""La convention de taux du calcul"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x15""xlInstrumentConvexity")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }