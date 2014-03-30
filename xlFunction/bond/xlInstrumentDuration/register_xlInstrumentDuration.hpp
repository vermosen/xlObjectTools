/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentDuration(const XLOPER & xDll) {

             // Enregistre la fonction xlInstrumentDuration
        Excel(xlfRegister, 0, 17, & xDll,
            TempStrNoSize("\x14""xlInstrumentDuration"),
            TempStrNoSize("\x09""PCPPEPCP#"),
            TempStrNoSize("\x13""INSTRUMENT.DURATION"),
            TempStrNoSize("\x6C""Identifiant de l'instrument,date d'évaluation,date de règlement,prix,type de duration,convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x52""Cette fonction calcule la duration de l'instrument pour un prix et une date donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x23""La date d'évaluation de la duration"),
            TempStrNoSize("\x1D""La date de règlement du titre"),
            TempStrNoSize("\x1E""Le type de duration à calculer"),
            TempStrNoSize("\x20""La convention de taux à utiliser"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentDuration(const XLOPER & xDll) {

        XLOPER xlRegID ;

        Excel(xlfRegister, 0, 17, & xDll,
            TempStrNoSize("\x14""xlInstrumentDuration"),
            TempStrNoSize("\x09""PCPPEPCP#"),
            TempStrNoSize("\x13""INSTRUMENT.DURATION"),
            TempStrNoSize("\x6C""Identifiant de l'instrument,date d'évaluation,date de règlement,prix,type de duration,convention,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x52""Cette fonction calcule la duration de l'instrument pour un prix et une date donnée"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x23""La date d'évaluation de la duration"),
            TempStrNoSize("\x1D""La date de règlement du titre"),
            TempStrNoSize("\x1E""Le type de duration à calculer"),
            TempStrNoSize("\x20""La convention de taux à utiliser"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x14""xlInstrumentDuration")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }