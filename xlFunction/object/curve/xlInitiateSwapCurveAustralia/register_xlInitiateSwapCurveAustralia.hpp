/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 21/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSwapCurveAustralia(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 20, & xDll,
            TempStrNoSize("\x1C""xlInitiateSwapCurveAustralia"),
            TempStrNoSize("\x0C""CCEPPPEECCP#"),
            TempStrNoSize("\x1B""INSTANCE.COURBE.SWAP.AUSSIE"),
            TempStrNoSize("\x9B""Identifiant de l'objet,Dates de calcul,Types d'instrument,Maturités,Cotations,Facteur de convexité,Facteur de retour à la moyenne,Libor 3M,Libor 6M,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x38""Le type d'instrument (DEPOSIT, FUTURE, SWAP3M OU SWAP6M)"),
            TempStrNoSize("\x1C""Les maturité des instruments"),
            TempStrNoSize("\x18""Le vecteur des cotations"),
            TempStrNoSize("\x2D""Le facteurs de convexité des contrats futures"),
            TempStrNoSize("\x2E""Le facteur de retour à la moyenne du processus"),
            TempStrNoSize("\x2D""L'identifiant de l'index de fixing Libor à 3M"),
            TempStrNoSize("\x2D""L'identifiant de l'index de fixing Libor à 6M"),
            TempStrNoSize("\x09""trigger  ")) ;

    }

inline void unregisterxlInitiateSwapCurveAustralia(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateSwapCurve
        Excel(xlfRegister, 0, 20, & xDll,
            TempStrNoSize("\x1C""xlInitiateSwapCurveAustralia"),
            TempStrNoSize("\x0C""CCEPPPEECCP#"),
            TempStrNoSize("\x1B""INSTANCE.COURBE.SWAP.AUSSIE"),
            TempStrNoSize("\x9B""Identifiant de l'objet,Dates de calcul,Types d'instrument,Maturités,Cotations,Facteur de convexité,Facteur de retour à la moyenne,Libor 3M,Libor 6M,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x5C""Cette fonction instancie une courbe de taux swap à partir des instruments passés en argument"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x11""La date de calcul"),
            TempStrNoSize("\x38""Le type d'instrument (DEPOSIT, FUTURE, SWAP3M OU SWAP6M)"),
            TempStrNoSize("\x1C""Les maturité des instruments"),
            TempStrNoSize("\x18""Le vecteur des cotations"),
            TempStrNoSize("\x2D""Le facteurs de convexité des contrats futures"),
            TempStrNoSize("\x2E""Le facteur de retour à la moyenne du processus"),
            TempStrNoSize("\x2D""L'identifiant de l'index de fixing Libor à 3M"),
            TempStrNoSize("\x2D""L'identifiant de l'index de fixing Libor à 6M"),
            TempStrNoSize("\x09""trigger  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1C""xlInitiateSwapCurveAustralia")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }