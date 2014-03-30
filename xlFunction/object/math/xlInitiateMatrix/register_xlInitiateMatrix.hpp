/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiatMatrix(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateUblasMatrix
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x10""xlInitiateMatrix"),
            TempStrNoSize("\x05""CCPP#"),
            TempStrNoSize("\x10""INSTANCE.MATRICE"),
            TempStrNoSize("\x35""identifiant de l'object,matrice à enregistrer,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x24""Cette fonction instancie une matrice"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x17""La matrice à instancier"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateMatrix(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateUblasMatrix
        Excel(xlfRegister, 0, 13, & xDll,
            TempStrNoSize("\x10""xlInitiateMatrix"),
            TempStrNoSize("\x05""CCPP#"),
            TempStrNoSize("\x10""INSTANCE.MATRICE"),
            TempStrNoSize("\x35""identifiant de l'object,matrice à enregistrer,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x24""Cette fonction instancie une matrice"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x17""La matrice à instancier"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x15""xlInitiateUblasMatrix")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }