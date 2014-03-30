/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositFuture(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDepositFuture
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x17""xlInitiateDepositFuture"),
            TempStrNoSize("\x0A""PCECPPPPP#"),
            TempStrNoSize("\x10""INSTANCE.DEPOFUT"),
            TempStrNoSize("\x8C""identifiant du future,date de référence,code maturité,calendrier,jours de règlement,convention jours ouvrés,convention de fin de mois,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2C""Cette fonction instancie un future sur dépôt"),
            TempStrNoSize("\x17""L'identifiant du future"),
            TempStrNoSize("\x14""La date de référence"),
            TempStrNoSize("\x1D""Le code de maturité du future"),
            TempStrNoSize("\x1D""Le calendrier de l'instrument"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x1E""La convention des jours ouvrés"),
            TempStrNoSize("\x1C""La convention de fin de mois"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateDepositFuture(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateDepositFuture
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x17""xlInitiateDepositFuture"),
            TempStrNoSize("\x0A""PCECPPPPP#"),
            TempStrNoSize("\x10""INSTANCE.DEPOFUT"),
            TempStrNoSize("\x8C""identifiant du future,date de référence,code maturité,calendrier,jours de règlement,convention jours ouvrés,convention de fin de mois,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2C""Cette fonction instancie un future sur dépôt"),
            TempStrNoSize("\x17""L'identifiant du future"),
            TempStrNoSize("\x14""La date de référence"),
            TempStrNoSize("\x1D""Le code de maturité du future"),
            TempStrNoSize("\x1D""Le calendrier de l'instrument"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x1E""La convention des jours ouvrés"),
            TempStrNoSize("\x1C""La convention de fin de mois"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x17""xlInitiateDepositFuture")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }