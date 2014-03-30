/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateCurveShift(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateCurveShift
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x14""xlInitiateCurveShift"),
            TempStrNoSize("\x07""PCPPCP#"),
            TempStrNoSize("\x0E""INSTANCE.SHIFT"),
            TempStrNoSize("\x4D""identifiant de l'objet,vecteur des gaps,vecteur des shifts,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2B""Cette fonction instancie un shift de courbe"),
            TempStrNoSize("\x16""L'identifiant du shift"),
            TempStrNoSize("\x1E""Les maturités exprimés en gaps"),
            TempStrNoSize("\x1B""Les valeurs de perturbation"),
            TempStrNoSize("\x1E""La convention de taux employée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateCurveShift(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateCurveShift
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x14""xlInitiateCurveShift"),
            TempStrNoSize("\x07""PCPPCP#"),
            TempStrNoSize("\x0E""INSTANCE.SHIFT"),
            TempStrNoSize("\x4D""identifiant de l'objet,vecteur des gaps,vecteur des shifts,convention,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2B""Cette fonction instancie un shift de courbe"),
            TempStrNoSize("\x16""L'identifiant du shift"),
            TempStrNoSize("\x1E""Les maturités exprimés en gaps"),
            TempStrNoSize("\x1B""Les valeurs de perturbation"),
            TempStrNoSize("\x1E""La convention de taux employée"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x26""xlInitiateCurveShift")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }