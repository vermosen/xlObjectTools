/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateFittedBondCurve(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateFittedBondCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x19""xlInitiateFittedBondCurve"),
            TempStrNoSize("\x0B""CCEEPPCCPP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.AJUSTEE"),
            TempStrNoSize("\x94""Identifiant de l'objet,Date de calcul,Jours de règlement,Identifiants des instruments,cotations,devise,méthode de fitting,règle de selection,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction instancie une courbe ajustée pour les instruments passés en argument"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x23""Les instruments composant la courbe"),
            TempStrNoSize("\x26""Le vecteur de cotation des instruments"),
            TempStrNoSize("\x22""La devise de cotation de la courbe"),
            TempStrNoSize("\x17""La méthode d'ajustement"),
            TempStrNoSize("\x20""La règle de sélection des titres"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateFittedBondCurve(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // supprime la fonction xlInitiateFittedBondCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x19""xlInitiateFittedBondCurve"),
            TempStrNoSize("\x0B""CCEEPPCCPP#"),
            TempStrNoSize("\x17""INSTANCE.COURBE.AJUSTEE"),
            TempStrNoSize("\x94""Identifiant de l'objet,Date de calcul,Jours de règlement,Identifiants des instruments,cotations,devise,méthode de fitting,règle de selection,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x53""Cette fonction instancie une courbe ajustée pour les instruments passés en argument"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x1F""Le nombre de jours de règlement"),
            TempStrNoSize("\x23""Les instruments composant la courbe"),
            TempStrNoSize("\x26""Le vecteur de cotation des instruments"),
            TempStrNoSize("\x22""La devise de cotation de la courbe"),
            TempStrNoSize("\x17""La méthode d'ajustement"),
            TempStrNoSize("\x20""La règle de sélection des titres"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x19""xlInitiateFittedBondCurve")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }