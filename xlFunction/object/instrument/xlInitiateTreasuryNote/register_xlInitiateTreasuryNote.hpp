/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateTreasuryNote (const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateMatrix
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x16""xlInitiateTreasuryNote"),
            TempStrNoSize("\x0A""PCEEEEEEP#"),
            TempStrNoSize("\x0F""INSTANCE.TNOTE"),
            TempStrNoSize("\x83""identifiant de l'instrument,date d'emission,date effective,premier coupon,penultième coupon,date de maturité,taux de coupon,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction instancie une obligation du trésor US"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul de premier coupon"),
            TempStrNoSize("\x25""La date de paiement du premier coupon"),
            TempStrNoSize("\x1C""La date du penultième coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'obligation"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateTreasuryNote (const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateMatrix
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x16""xlInitiateTreasuryNote"),
            TempStrNoSize("\x0A""PCEEEEEEP#"),
            TempStrNoSize("\x0F""INSTANCE.TNOTE"),
            TempStrNoSize("\x83""identifiant de l'instrument,date d'emission,date effective,premier coupon,penultième coupon,date de maturité,taux de coupon,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x34""Cette fonction instancie une obligation du trésor US"),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul de premier coupon"),
            TempStrNoSize("\x25""La date de paiement du premier coupon"),
            TempStrNoSize("\x1C""La date du penultième coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'obligation"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0F""xlInitiateTNote")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }