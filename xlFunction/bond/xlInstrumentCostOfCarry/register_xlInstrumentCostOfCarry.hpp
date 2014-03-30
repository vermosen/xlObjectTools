/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInstrumentCostOfCarry(const XLOPER & xDll) {


             // Enregistre la fonction xlInstrumentCostOfCarry
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x17""xlInstrumentCostOfCarry"),
            TempStrNoSize("\x08""PCCEEEP#"),
            TempStrNoSize("\x17""INSTRUMENT.COUT.PORTAGE"),
            TempStrNoSize("\x81""Identifiant de l'instrument,Identifiant de la courbe,Prix de l'instrument,Date de début de portage,Date de fin de portage,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x47""Cette fonction calcule le prix final du titre déduit du coût de portage. Les coupons intermédiaires sont replacés au taux spécifié"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x2C""L'identifiant de la courbe de capitalisation"),
            TempStrNoSize("\x35""Le prix de l'instrument à la date de début de portage"),
            TempStrNoSize("\x1B""La date de début de portage"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }


inline void unregisterxlInstrumentCostOfCarry(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction xlInstrumentCostOfCarry
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x17""xlInstrumentCostOfCarry"),
            TempStrNoSize("\x08""PCCEEEP#"),
            TempStrNoSize("\x17""INSTRUMENT.COUT.PORTAGE"),
            TempStrNoSize("\x81""Identifiant de l'instrument,Identifiant de la courbe,Prix de l'instrument,Date de début de portage,Date de fin de portage,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Bond"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x47""Cette fonction calcule le prix final du titre déduit du coût de portage. Les coupons intermédiaires sont replacés au taux spécifié"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x2C""L'identifiant de la courbe de capitalisation"),
            TempStrNoSize("\x35""Le prix de l'instrument à la date de début de portage"),
            TempStrNoSize("\x1B""La date de début de portage"),
            TempStrNoSize("\x19""La date de fin de portage"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x17""xlInstrumentCostOfCarry")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }