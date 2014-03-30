/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/01/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateBtan (const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateBuNote
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x0E""xlInitiateBtan"),
            TempStrNoSize("\x0A""PCEEEEEEP#"),
            TempStrNoSize("\x0D""INSTANCE.BTAN"),
            TempStrNoSize("\x83""identifiant de l'instrument,date d'emission,date effective,premier coupon,penultième coupon,date de maturité,taux de coupon,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un billet de trésorerie du trésor francais"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul de premier coupon"),
            TempStrNoSize("\x25""La date de paiement du premier coupon"),
            TempStrNoSize("\x1C""La date du penultième coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'obligation"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateBtan (const XLOPER & xDll) {

        XLOPER xlRegID ;

             // décharge la fonction xlInitiateBuNote
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x0E""xlInitiateBtan"),
            TempStrNoSize("\x0A""PCEEEEEEP#"),
            TempStrNoSize("\x0D""INSTANCE.BTAN"),
            TempStrNoSize("\x83""identifiant de l'instrument,date d'emission,date effective,premier coupon,penultième coupon,date de maturité,taux de coupon,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un billet de trésorerie du trésor francais"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul de premier coupon"),
            TempStrNoSize("\x25""La date de paiement du premier coupon"),
            TempStrNoSize("\x1C""La date du penultième coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'obligation"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0E""xlInitiateBtan")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }