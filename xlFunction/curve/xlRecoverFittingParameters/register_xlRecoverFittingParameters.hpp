/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlRecoverFittingParameters(const XLOPER & xDll) {

             // Enregistre la fonction xlRecoverFittingParameters
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x1A""xlRecoverFittingParameters"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x19""FITTING.PARAMETRES.COURBE"),
            TempStrNoSize("\x20""Identifiant de la courbe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5E""Cette fonction extrait les paramètres de calcul de la courbe de Nelson-Siegel-Svensson pointée"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

    }

inline void unregisterxlRecoverFittingParameters(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlRecoverNSSParameters
        Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x1A""xlRecoverFittingParameters"),
            TempStrNoSize("\x04""PCP#"),
            TempStrNoSize("\x19""FITTING.PARAMETRES.COURBE"),
            TempStrNoSize("\x20""Identifiant de la courbe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5E""Cette fonction extrait les paramètres de calcul de la courbe de Nelson-Siegel-Svensson pointée"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x17""Déclanche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1A""xlRecoverFittingParameters")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }