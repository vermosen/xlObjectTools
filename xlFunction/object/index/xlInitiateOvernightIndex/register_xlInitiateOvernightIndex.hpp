/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 29/05/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateOvernightIndex(const XLOPER & xDll) {


             // Enregistre la fonction xlInitiateOvernightIndex
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x1A""xlInitiateOvernightIndex"),
            TempStrNoSize("\x08""CCPPCCP#"),
            TempStrNoSize("\x18""INSTANCE.INDEX.OVERNIGHT"),
            TempStrNoSize("\x5F""Identifiant de l'objet,historique de fixing,jours de règlement,calendrier,base annuelle,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2B""Cette fonction instancie un index overnight"),
            TempStrNoSize("\x18""L'identifiant de l'objet"),
            TempStrNoSize("\x16""Historique des fixings"),
            TempStrNoSize("\x21""Les jours de règlement de l'index"),
            TempStrNoSize("\x19""Le calendrier des fixings"),
            TempStrNoSize("\x10""La base annuelle"),
            TempStrNoSize("\x09""trigger  ")) ;


    }

inline void unregisterxlInitiateOvernightIndex(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateOvernightIndex
        Excel(xlfRegister, 0, 16, & xDll,
            TempStrNoSize("\x1A""xlInitiateOvernightIndex"),
            TempStrNoSize("\x08""CCPPCCP#"),
            TempStrNoSize("\x18""INSTANCE.INDEX.OVERNIGHT"),
            TempStrNoSize("\x5F""Identifiant de l'objet,historique de fixing,jours de règlement,calendrier,base annuelle,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2B""Cette fonction instancie un index overnight"),
            TempStrNoSize("\x18""L'identifiant de l'objet"),
            TempStrNoSize("\x16""Historique des fixings"),
            TempStrNoSize("\x21""Les jours de règlement de l'index"),
            TempStrNoSize("\x19""Le calendrier des fixings"),
            TempStrNoSize("\x10""La base annuelle"),
            TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1A""xlInitiateOvernightIndex")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }
