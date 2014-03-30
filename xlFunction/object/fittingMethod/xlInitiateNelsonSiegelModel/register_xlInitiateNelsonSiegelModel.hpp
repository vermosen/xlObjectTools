/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 03/01/2011
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateNelsonSiegelModel (const XLOPER & xDll) {


             // Enregistre la fonction xlInitiateNelsonSiegelModel
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x1B""xlInitiateNelsonSiegelModel"),
            TempStrNoSize("\x07""PCPPPP#"),
            TempStrNoSize("\x1E""INSTANCE.FITTING.NELSON.SIEGEL"),
            TempStrNoSize("\x36""identifiant,vecteur de départ,lambda,précision,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x55""Cette fonction instancie les paramètres d'un fitting selon le modèle de Nelson-Siegel"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x21""Le vecteur des paramètres initial"),
            TempStrNoSize("\x16""Le paramètre d'échelle"),
            TempStrNoSize("\x1F""La précision du fitting désirée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;


    }

inline void unregisterxlInitiateNelsonSiegelModel (const XLOPER & xDll) {


        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateNelsonSiegelModel
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x1B""xlInitiateNelsonSiegelModel"),
            TempStrNoSize("\x07""PCPPPP#"),
            TempStrNoSize("\x1E""INSTANCE.FITTING.NELSON.SIEGEL"),
            TempStrNoSize("\x36""identifiant,vecteur de départ,lambda,précision,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x55""Cette fonction instancie les paramètres d'un fitting selon le modèle de Nelson-Siegel"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x21""Le vecteur des paramètres initial"),
            TempStrNoSize("\x16""Le paramètre d'échelle"),
            TempStrNoSize("\x1F""La précision du fitting désirée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1B""xlInitiateNelsonSiegelModel")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;


    }