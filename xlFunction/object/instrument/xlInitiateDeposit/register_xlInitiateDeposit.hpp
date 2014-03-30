/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 19/12/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDeposit(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDeposit
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x11""xlInitiateDeposit"),
            TempStrNoSize("\x0A""PCPEPPPPP#"),
            TempStrNoSize("\x0D""INSTANCE.DEPO"),
            TempStrNoSize("\x8C""identifiant du dépôt,date de valeur,date de maturité,calendrier,jours de règlement,convention jours ouvrés,convention de fin de mois,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x21""Cette fonction instancie un dépôt"),
            TempStrNoSize("\x16""L'identifiant du dépôt"),
            TempStrNoSize("\x21""La date de valeur de l'instrument"),
            TempStrNoSize("\x1C""La date de maturité du dépôt"),
            TempStrNoSize("\x1D""Le calendrier de l'instrument"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x1E""La convention des jours ouvrés"),
            TempStrNoSize("\x1C""La convention defins de mois"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateDeposit(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateDeposit
        Excel(xlfRegister, 0, 18, & xDll,
            TempStrNoSize("\x11""xlInitiateDeposit"),
            TempStrNoSize("\x0A""PCPEPPPPP#"),
            TempStrNoSize("\x0D""INSTANCE.DEPO"),
            TempStrNoSize("\x8C""identifiant du dépôt,date de valeur,date de maturité,calendrier,jours de règlement,convention jours ouvrés,convention de fin de mois,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x21""Cette fonction instancie un dépôt"),
            TempStrNoSize("\x16""L'identifiant du dépôt"),
            TempStrNoSize("\x21""La date de valeur de l'instrument"),
            TempStrNoSize("\x1C""La date de maturité du dépôt"),
            TempStrNoSize("\x1D""Le calendrier de l'instrument"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x1E""La convention des jours ouvrés"),
            TempStrNoSize("\x1C""La convention defins de mois"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x14""xlInitiateDeposit")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }