/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlSchurEigenVector(const XLOPER & xDll) {

             // Enregistre la fonction xlSchurEigenVector
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlSchurEigenVector"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x16""VECTEURS.PROPRES.SCHUR"),
            TempStrNoSize("\x1F""identifiant de l'object,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x48""Cette fonction fournit les vecteurs propres de la décomposition de Schur"),
            TempStrNoSize("\x26""Identifiant de la matrice à décomposer"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

    }

inline void unregisterxlSchurEigenVector(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlSchurEigenVector
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x12""xlSchurEigenVector"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x16""VECTEURS.PROPRES.SCHUR"),
            TempStrNoSize("\x1F""identifiant de l'object,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x48""Cette fonction fournit les vecteurs propres de la décomposition de Schur"),
            TempStrNoSize("\x26""Identifiant de la matrice à décomposer"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x12""xlSchurEigenVector")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }