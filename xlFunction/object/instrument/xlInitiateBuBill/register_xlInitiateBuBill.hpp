/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateBuBill (const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateAussieBill
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x10""xlInitiateBuBill"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x10""INSTANCE.BU.BILL"),
            TempStrNoSize("\x44""identifiant de l'instrument,date d'emission,date de maturité,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3C""Cette fonction instancie un bill émis par le trésor allemand"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateBuBill (const XLOPER & xDll) {

        XLOPER xlRegID ;

             // décharge la fonction xlInitiateAussieBill
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x10""xlInitiateBuBill"),
            TempStrNoSize("\x06""PCEEP#"),
            TempStrNoSize("\x10""INSTANCE.BU.BILL"),
            TempStrNoSize("\x44""identifiant de l'instrument,date d'emission,date de maturité,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3C""Cette fonction instancie un bill émis par le trésor allemand"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x10""xlInitiateBuBill")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }