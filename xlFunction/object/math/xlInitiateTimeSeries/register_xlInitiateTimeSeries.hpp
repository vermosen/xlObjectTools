/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateTimeSeries(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateTimeSeries
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x14""xlInitiateTimeSeries"),
            TempStrNoSize("\x06""CCPPP#"),
            TempStrNoSize("\x19""INSTANCE.SERIE.TEMPORELLE"),
            TempStrNoSize("\x3E""identifiant de l'object,plage de date,plage de valeurs,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2D""Cette fonction instancie une serie temporelle"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x12""La plage des dates"),
            TempStrNoSize("\x14""La plage des données"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateTimeSeries(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateMatrix
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x14""xlInitiateTimeSeries"),
            TempStrNoSize("\x06""CCPPP#"),
            TempStrNoSize("\x19""INSTANCE.SERIE.TEMPORELLE"),
            TempStrNoSize("\x3E""identifiant de l'object,plage de date,plage de valeurs,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2D""Cette fonction instancie une serie temporelle"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x12""La plage des dates"),
            TempStrNoSize("\x14""La plage des données"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x10""xlInitiateTimeSeries")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }