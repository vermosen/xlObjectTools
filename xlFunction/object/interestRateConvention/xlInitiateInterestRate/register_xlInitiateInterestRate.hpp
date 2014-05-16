/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateInterestRate(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x16""xlInitiateInterestRate"),
            TempStrNoSize("\x09""PCCCCCP#!"),
            TempStrNoSize("\x18""INSTANCE.CONVENTION.TAUX"),
            TempStrNoSize("\x6B""Identifiant de l'objet,base annuelle,composition des intérêts,fréquence,convention des jours ouvrés,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2F""Cette fonction instancie une convention de taux"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x10""La base annuelle"),
            TempStrNoSize("\x1B""La composition des intérêts"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x2A""La convention des jours ouvrés à appliquer"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateInterestRate(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x16""xlInitiateInterestRate"),
            TempStrNoSize("\x09""PCCCCCP#!"),
            TempStrNoSize("\x18""INSTANCE.CONVENTION.TAUX"),
            TempStrNoSize("\x6B""Identifiant de l'objet,base annuelle,composition des intérêts,fréquence,convention des jours ouvrés,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2F""Cette fonction instancie une convention de taux"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x10""La base annuelle"),
            TempStrNoSize("\x1B""La composition des intérêts"),
            TempStrNoSize("\x16""La fréquence de coupon"),
            TempStrNoSize("\x2A""La convention des jours ouvrés à appliquer"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;


        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x16""xlInitiateInterestRate")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }