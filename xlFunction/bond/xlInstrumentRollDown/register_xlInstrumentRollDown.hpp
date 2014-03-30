/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 17/01/2010
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentRollDown(const XLOPER & xDll) {

             // Enregistre la fonction xlInstrumentRollDown
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x14""xlInstrumentRollDown"),
            TempStrNoSize("\x08""PCCEPPP#"),
            TempStrNoSize("\x14""INSTRUMENT.ROLL.DOWN"),
            TempStrNoSize("\x6E""Identifiant de l'instrument,identifiant de la courbe,date de fin,spread initial,convention de taux,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x79""Cette fonction calcule le prix à terme d'un instrument pour un spread et une courbe spot et à un horizon de portage donné"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1A""L'identifiant de la courbe"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x2B""Le spread de l'instrument en points de base"),
            TempStrNoSize("\x27""L'identifiant de la convention employée"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

    }

inline void unregisterxlInstrumentRollDown(const XLOPER & xDll) {

        XLOPER xlRegID ;

        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x14""xlInstrumentRollDown"),
            TempStrNoSize("\x08""PCCEPPP#"),
            TempStrNoSize("\x14""INSTRUMENT.ROLL.DOWN"),
            TempStrNoSize("\x6E""Identifiant de l'instrument,identifiant de la courbe,date de fin,spread initial,convention de taux,déclencheur"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x79""Cette fonction calcule le prix à terme d'un instrument pour un spread et une courbe spot et à un horizon de portage donné"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1A""L'identifiant de la courbe"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x2B""Le spread de l'instrument en points de base"),
            TempStrNoSize("\x27""L'identifiant de la convention employée"),
            TempStrNoSize("\x1C""Le déclencheur du recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x14""xlInstrumentRollDown")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }