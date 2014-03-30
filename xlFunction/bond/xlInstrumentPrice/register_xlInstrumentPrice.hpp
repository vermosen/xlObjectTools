/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 15/11/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentPrice(const XLOPER & xDll) {

             // Enregistre la fonction xlInstrumentPrice
        Excel(xlfRegister, 0, 15, & xDll,
              TempStrNoSize("\x11""xlInstrumentPrice"),
              TempStrNoSize("\x07""PCPEPP#"),
              TempStrNoSize("\x0F""INSTRUMENT.PRIX"),
              TempStrNoSize("\x42""identifiant,date de réglement,taux de rendement,convention,trigger"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x15""xlObjectTools - Bond"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x51""Cette fonction calcule le prix de l'instrument à partir de son taux conventionel."),
              TempStrNoSize("\x1D""L'identifiant de l'instrument"),
              TempStrNoSize("\x24""La date de réglement de l'instrument"),
              TempStrNoSize("\x31""Le taux de l'instrument pour la convention donnée"),
              TempStrNoSize("\x26""L'identifiant de la convention de taux"),
              TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentPrice(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInstrumentPrice
        Excel(xlfRegister, 0, 15, & xDll,
              TempStrNoSize("\x11""xlInstrumentPrice"),
              TempStrNoSize("\x07""PCPEPP#"),
              TempStrNoSize("\x0F""INSTRUMENT.PRIX"),
              TempStrNoSize("\x42""identifiant,date de réglement,taux de rendement,convention,trigger"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x15""xlObjectTools - Bond"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x51""Cette fonction calcule le prix de l'instrument à partir de son taux conventionel."),
              TempStrNoSize("\x1D""L'identifiant de l'instrument"),
              TempStrNoSize("\x24""La date de réglement de l'instrument"),
              TempStrNoSize("\x31""Le taux de l'instrument pour la convention donnée"),
              TempStrNoSize("\x26""L'identifiant de la convention de taux"),
              TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
               TempStrNoSize("\x11""xlInstrumentPrice")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }