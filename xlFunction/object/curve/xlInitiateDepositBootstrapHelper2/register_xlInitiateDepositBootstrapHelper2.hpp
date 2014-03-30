/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009 Banque de France. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateDepositBootstrapHelper2(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateDepositBootstrapHelper2
        Excel(xlfRegister, 0, 17, & xDll,
              TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2"),
              TempStrNoSize("\x09""PCEPPEPP#"),
              TempStrNoSize("\x1D""INSTANCE.INTERPOLATION.DEPOT2"),
              TempStrNoSize("\x69""Identifiant de l'objet,date de maturité,calendrier,jours de règlement,taux de dépôt,base annuelle,Trigger"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x17""xlObjectTools - Object"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x43""Cette fonction instancie un dépôt pour l'interpolation d'une courbe"),
              TempStrNoSize("\x19""L'identifiant de l'object"),
              TempStrNoSize("\x16""La date de maturité du dépôt"),
			  TempStrNoSize("\x1A""Le calendrier de référence"),
			  TempStrNoSize("\x1F""Le nombre de jours de règlement"),
              TempStrNoSize("\x10""Le taux du dépôt"),
			  TempStrNoSize("\x10""La base annuelle"),
              TempStrNoSize("\x09""trigger  ")) ;

    }


inline void unregisterxlInitiateDepositBootstrapHelper2(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateDepositBootstrapHelper2
        Excel(xlfRegister, 0, 17, & xDll,
              TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2"),
              TempStrNoSize("\x09""PCEPPEPP#"),
              TempStrNoSize("\x1D""INSTANCE.INTERPOLATION.DEPOT2"),
              TempStrNoSize("\x69""Identifiant de l'objet,date de maturité,calendrier,jours de règlement,taux de dépôt,base annuelle,Trigger"),
              TempStrNoSize("\x01""1"),
              TempStrNoSize("\x17""xlObjectTools - Object"),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x00"""),
              TempStrNoSize("\x43""Cette fonction instancie un dépôt pour l'interpolation d'une courbe"),
              TempStrNoSize("\x19""L'identifiant de l'object"),
              TempStrNoSize("\x16""La date de maturité du dépôt"),
			  TempStrNoSize("\x1A""Le calendrier de référence"),
			  TempStrNoSize("\x1F""Le nombre de jours de règlement"),
              TempStrNoSize("\x10""Le taux du dépôt"),
			  TempStrNoSize("\x10""La base annuelle"),
              TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x21""xlInitiateDepositBootstrapHelper2")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }
