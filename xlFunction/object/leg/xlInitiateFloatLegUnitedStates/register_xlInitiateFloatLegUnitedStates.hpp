/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateFloatLegUnitedStates(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateFloatLeg
        Excel(xlfRegister, 0, 21, & xDll,
            TempStrNoSize("\x1E""xlInitiateFloatLegUnitedStates"),
            TempStrNoSize("\x0D""PCEPPEPCPPPP#"),
            TempStrNoSize("\x25""INSTANCE.JAMBE.VARIABLE.UNITED.STATES"),
            TempStrNoSize("\xAC""Identifiant de l'instrument,date effective,date de premier coupon,date de dernier coupon,date de maturité,notionel,index de référence,fréquence,base annuelle,spread,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3E""Cette fonction instancie une jambe variable de swap en dollar."),
            TempStrNoSize("\x19""L'identifiant de la jambe"),
            TempStrNoSize("\x2B""La date de début de cumul du premier coupon"),
            TempStrNoSize("\x19""La date du premier coupon"),
            TempStrNoSize("\x19""La date de dernier coupon"),
            TempStrNoSize("\x1F""La date de maturité de la jambe"),
            TempStrNoSize("\x16""Le notionel du contrat"),
            TempStrNoSize("\x18""L'identifiant de l'index"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x1C""La base annuelle de la jambe"),
            TempStrNoSize("\x15""Le spread de la jambe"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateFloatLegUnitedStates(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateFloatLeg
        Excel(xlfRegister, 0, 21, & xDll,
            TempStrNoSize("\x1E""xlInitiateFloatLegUnitedStates"),
            TempStrNoSize("\x0D""PCEPPEPCPPPP#"),
            TempStrNoSize("\x25""INSTANCE.JAMBE.VARIABLE.UNITED.STATES"),
            TempStrNoSize("\xAC""Identifiant de l'instrument,date effective,date de premier coupon,date de dernier coupon,date de maturité,notionel,index de référence,fréquence,base annuelle,spread,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x3E""Cette fonction instancie une jambe variable de swap en dollar."),
            TempStrNoSize("\x19""L'identifiant de la jambe"),
            TempStrNoSize("\x2B""La date de début de cumul du premier coupon"),
            TempStrNoSize("\x19""La date du premier coupon"),
            TempStrNoSize("\x19""La date de dernier coupon"),
            TempStrNoSize("\x1F""La date de maturité de la jambe"),
            TempStrNoSize("\x16""Le notionel du contrat"),
            TempStrNoSize("\x18""L'identifiant de l'index"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x1C""La base annuelle de la jambe"),
            TempStrNoSize("\x15""Le spread de la jambe"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1E""xlInitiateFloatLegUnitedStates")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }