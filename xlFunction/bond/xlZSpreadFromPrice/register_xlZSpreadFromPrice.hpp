/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlZSpreadFromPrice(const XLOPER & xDll) {

             // Enregistre la fonction xlZSpreadFromPrice
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x12""xlZSpreadFromPrice"),
            TempStrNoSize("\x08""PCCEPPP#"),
            TempStrNoSize("\x13""INSTRUMENT.Z.SPREAD"),
            TempStrNoSize("\x62""Identifiant de l'instrument,Identifiant de la courbe,Prix,Convention,Date de règlement,Déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x39""Cette fonction calcule le z-spread de l'instrument en bps"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x16""La courbe de référence"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x30""L'identifiant de la convention de calcul du taux"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlZSpreadFromPrice(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlTNoteTheoreticalPrice
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x12""xlZSpreadFromPrice"),
            TempStrNoSize("\x08""PCCEPPP#"),
            TempStrNoSize("\x13""INSTRUMENT.Z.SPREAD"),
            TempStrNoSize("\x62""Identifiant de l'instrument,Identifiant de la courbe,Prix,Convention,Date de règlement,Déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x39""Cette fonction calcule le z-spread de l'instrument en bps"),
            TempStrNoSize("\x16""Le nom de l'instrument"),
            TempStrNoSize("\x16""La courbe de référence"),
            TempStrNoSize("\x17""Le prix de l'instrument"),
            TempStrNoSize("\x30""L'identifiant de la convention de calcul du taux"),
            TempStrNoSize("\x24""La date de règlement de l'instrument"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;


        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlZSpreadFromPrice")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }