/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 03/01/2011
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSvenssonModel(const XLOPER & xDll) {


             // Enregistre la fonction xlInitiateSvenssonModel
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x17""xlInitiateSvenssonModel"),
            TempStrNoSize("\x0B""PCPPPPPPPP#"),
            TempStrNoSize("\x19""INSTANCE.FITTING.SVENSSON"),
            TempStrNoSize("\xAE""identifiant de l'objet,type de contrainte,vecteur initial,matrice de perturbation,nombre de cycles par fil,nombre d'itérations,itération maximales par cycle,précision,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x71""Cette fonction instancie les paramètres d'un fitting selon le modèle de Svensson avec la méthode du recuit simulé"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x35""Le type de contrainte imposé à la méthode de Svensson"),
            TempStrNoSize("\x21""Le vecteur des paramètres initial"),
            TempStrNoSize("\x2B""La matrice des perturbations des paramètres"),
            TempStrNoSize("\x25""Le nombre de cycles par fil de calcul"),
            TempStrNoSize("\x28""Le nombre maximal d'itérations par cycle"),
            TempStrNoSize("\x20""Le nombre d'itérations de calcul"),
            TempStrNoSize("\x1F""La précision du fitting désirée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInitiateSvenssonModel(const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Libère la fonction xlInitiateSvenssonModel
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x17""xlInitiateSvenssonModel"),
            TempStrNoSize("\x0B""PCPPPPPPPP#"),
            TempStrNoSize("\x19""INSTANCE.FITTING.SVENSSON"),
            TempStrNoSize("\xAE""identifiant de l'objet,type de contrainte,vecteur initial,matrice de perturbation,nombre de cycles par fil,nombre d'itérations,itération maximales par cycle,précision,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x71""Cette fonction instancie les paramètres d'un fitting selon le modèle de Svensson avec la méthode du recuit simulé"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x35""Le type de contrainte imposé à la méthode de Svensson"),
            TempStrNoSize("\x21""Le vecteur des paramètres initial"),
            TempStrNoSize("\x2B""La matrice des perturbations des paramètres"),
            TempStrNoSize("\x25""Le nombre de cycles par fil de calcul"),
            TempStrNoSize("\x28""Le nombre maximal d'itérations par cycle"),
            TempStrNoSize("\x20""Le nombre d'itérations de calcul"),
            TempStrNoSize("\x1F""La précision du fitting désirée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x17""xlInitiateSvenssonModel")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }