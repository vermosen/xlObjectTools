/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateTreasuryBill(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateTreasuryBill
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x16""xlInitiateTreasuryBill"),
            TempStrNoSize("\x06""CCEEP#"),
            TempStrNoSize("\x0F""INSTANCE.TBILL"),
            TempStrNoSize("\x44""identifiant de l'instrument,date d'émission,date de maturité,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3D""Cette fonction instancie un instrument monétaire du trésor US"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateTreasuryBill(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateTreasuryBill
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x16""xlInitiateTreasuryBill"),
            TempStrNoSize("\x06""CCEEP#"),
            TempStrNoSize("\x0F""INSTANCE.TBILL"),
            TempStrNoSize("\x44""identifiant de l'instrument,date d'émission,date de maturité,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3D""Cette fonction instancie un instrument monétaire du trésor US"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0F""xlInitiatetreasuryBill")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }