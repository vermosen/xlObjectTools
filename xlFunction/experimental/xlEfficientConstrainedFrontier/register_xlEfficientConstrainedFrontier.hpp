/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 12/10/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

void registerxlEfficientConstrainedFrontier(const XLOPER & xDll) {

             // Enregistre la fonction xlEfficientConstrainedFrontier
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1E""xlEfficientConstrainedFrontier"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x14""FRONTIERE.EFFICIENTE"),
            TempStrNoSize("\x50""vecteur des rendements,matrice de variance-covariance,seuil de rendement,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x62""Cette fonction applique une optimisation au problème de frontière efficiente muni d'une contrainte"),
            TempStrNoSize("\x25""L'identifiant du vecteur de rendement"),
            TempStrNoSize("\x32""L'identifiant de la matrice de variance-covariance"),
            TempStrNoSize("\x15""Le seuil de rendement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

void unregisterxlEfficientConstrainedFrontier(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // libère la fonction xlEfficientConstrainedFrontier
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1E""xlEfficientConstrainedFrontier"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x14""FRONTIERE.EFFICIENTE"),
            TempStrNoSize("\x50""vecteur des rendements,matrice de variance-covariance,seuil de rendement,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Test"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x62""Cette fonction applique une optimisation au problème de frontière efficiente muni d'une contrainte"),
            TempStrNoSize("\x25""L'identifiant du vecteur de rendement"),
            TempStrNoSize("\x32""L'identifiant de la matrice de variance-covariance"),
            TempStrNoSize("\x15""Le seuil de rendement"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1E""xlEfficientConstrainedFrontier")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }