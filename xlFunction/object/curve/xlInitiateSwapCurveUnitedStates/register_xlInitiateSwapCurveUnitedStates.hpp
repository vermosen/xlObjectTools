/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSwapCurveUnitedStates(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x1F""xlInitiateSwapCurveUnitedStates"),
            TempStrNoSize("\x0B""CCEPPPEECP#"),
            TempStrNoSize("\x22""INSTANCE.COURBE.SWAP.UNITED.STATES"),
            TempStrNoSize("\x95""Identifiant de l'objet,Dates de calcul,Types d'instrument,Maturités,Cotations,Facteur de convexité,Facteur de retour à la moyenne,Libor Index,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x2E""Le type d'instrument (DEPOSIT, FUTURE ou SWAP)"),
            TempStrNoSize("\x1C""Les maturité des instruments"),
            TempStrNoSize("\x18""Le vecteur des cotations"),
            TempStrNoSize("\x2D""Le facteurs de convexité des contrats futures"),
            TempStrNoSize("\x2E""Le facteur de retour à la moyenne du processus"),
            TempStrNoSize("\x28""L'identifiant de l'index de fixing Libor"),
            TempStrNoSize("\x09""trigger  ")) ;

    }

inline void unregisterxlInitiateSwapCurveUnitedStates(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x1F""xlInitiateSwapCurveUnitedStates"),
            TempStrNoSize("\x0B""CCEPPPEECP#"),
            TempStrNoSize("\x22""INSTANCE.COURBE.SWAP.UNITED.STATES"),
            TempStrNoSize("\x95""Identifiant de l'objet,Dates de calcul,Types d'instrument,Maturités,Cotations,Facteur de convexité,Facteur de retour à la moyenne,Libor Index,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x2E""Le type d'instrument (DEPOSIT, FUTURE ou SWAP)"),
            TempStrNoSize("\x1C""Les maturité des instruments"),
            TempStrNoSize("\x18""Le vecteur des cotations"),
            TempStrNoSize("\x2D""Le facteurs de convexité des contrats futures"),
            TempStrNoSize("\x2E""Le facteur de retour à la moyenne du processus"),
            TempStrNoSize("\x28""L'identifiant de l'index de fixing Libor"),
            TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1F""xlInitiateSwapCurveUnitedStates")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }