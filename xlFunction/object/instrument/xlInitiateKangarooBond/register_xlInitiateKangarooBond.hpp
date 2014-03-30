/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateKangarooBond(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateKangarooBond
        Excel(xlfRegister, 0, 23, & xDll,
            TempStrNoSize("\x16""xlInitiateKangarooBond"),
            TempStrNoSize("\x0F""PCEPPPEEPPPPPP#"),
            TempStrNoSize("\x11""INSTANCE.KANGAROO"),
            TempStrNoSize("\xD6""identifiant de l'instrument,date d'émission,date effective,date de premier coupon,date de dernier coupon,date de maturité,taux de coupon,fréquence,base annuelle,jours de règlement,règle EOM,ex-dividend days,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x42""Cette fonction instancie un instrument euro obligataire en dollar."),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul du premier coupon"),
            TempStrNoSize("\x19""La date du premier coupon"),
            TempStrNoSize("\x19""La date de dernier coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'instrument"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x19""La base annuelle du titre"),
            TempStrNoSize("\x20""Le nombre de jours de règlements"),
            TempStrNoSize("\x22""La règle de gestion de fin de mois"),
            TempStrNoSize("\x1E""Le nombre de jours ex-dividend"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateKangarooBond(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateKangarooBond
        Excel(xlfRegister, 0, 23, & xDll,
            TempStrNoSize("\x16""xlInitiateKangarooBond"),
            TempStrNoSize("\x0F""PCEPPPEEPPPPPP#"),
            TempStrNoSize("\x11""INSTANCE.KANGAROO"),
            TempStrNoSize("\xD6""identifiant de l'instrument,date d'émission,date effective,date de premier coupon,date de dernier coupon,date de maturité,taux de coupon,fréquence,base annuelle,jours de règlement,règle EOM,ex-dividend days,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x42""Cette fonction instancie un instrument euro obligataire en dollar."),
            TempStrNoSize("\x1D""L'identifiant de l'instrument"),
            TempStrNoSize("\x1B""La date d'émission du titre"),
            TempStrNoSize("\x2B""La date de début de cumul du premier coupon"),
            TempStrNoSize("\x19""La date du premier coupon"),
            TempStrNoSize("\x19""La date de dernier coupon"),
            TempStrNoSize("\x1C""La date de maturité du titre"),
            TempStrNoSize("\x21""Le taux de coupon de l'instrument"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x19""La base annuelle du titre"),
            TempStrNoSize("\x20""Le nombre de jours de règlements"),
            TempStrNoSize("\x22""La règle de gestion de fin de mois"),
            TempStrNoSize("\x1E""Le nombre de jours ex-dividend"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x16""xlInitiateKangarooBond")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }