/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateFittedBondDiscountCurve(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateFittedBondCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve"),
            TempStrNoSize("\x0B""CCPPPPCCCP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.AJUSTEE"),
            TempStrNoSize("\x84""Identifiant de l'objet,Date de calcul,Date de règlement,Identifiants des instruments,cotations,calendrier,méthode de fitting,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction instancie une courbe ajustée pour les instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x21""La date de règlement de la courbe"),
            TempStrNoSize("\x23""Les instruments composant la courbe"),
            TempStrNoSize("\x26""Le vecteur de cotation des instruments"),
            TempStrNoSize("\x22""La devise de cotation de la courbe"),
            TempStrNoSize("\x17""La méthode d'ajustement"),
			TempStrNoSize("\x1F""La règle de selection des titres"),
            TempStrNoSize("\x09""trigger  ")) ;

    }


inline void unregisterxlInitiateFittedBondDiscountCurve(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateFittedBondCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve"),
            TempStrNoSize("\x0B""CCPPPPCCCP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.AJUSTEE"),
            TempStrNoSize("\x84""Identifiant de l'objet,Date de calcul,Date de règlement,Identifiants des instruments,cotations,calendrier,méthode de fitting,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction instancie une courbe ajustée pour les instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x21""La date de règlement de la courbe"),
            TempStrNoSize("\x23""Les instruments composant la courbe"),
            TempStrNoSize("\x26""Le vecteur de cotation des instruments"),
            TempStrNoSize("\x22""La devise de cotation de la courbe"),
            TempStrNoSize("\x17""La méthode d'ajustement"),
			TempStrNoSize("\x1F""La règle de selection des titres"),
            TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x21""xlInitiateFittedBondDiscountCurve")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }