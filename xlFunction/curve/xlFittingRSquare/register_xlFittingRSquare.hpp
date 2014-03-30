/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlFittingRSquare(const XLOPER & xDll) {

             // Enregistre la fonction xlFittingRSquare
         Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x10""xlFittingRSquare"),
            TempStrNoSize("\x04""BCP#"),
            TempStrNoSize("\x21""FITTING.COEFFICIENT.DETERMINATION"),
            TempStrNoSize("\x23""nom de la courbe à analyser,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x9C""Cette fonction fournit le coefficient de détermination pour une courbe du type NSS (somme des carrés des résidus pondérés par lse durations des instruments)"),
            TempStrNoSize("\x1E""Le nom de la courbe à analyser"),
            TempStrNoSize("\x21""Un déclencheur pour le recalcul  ")) ;

    }

inline void unregisterxlFittingRSquare(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlFittingRSquare
         Excel(xlfRegister, 0, 12, & xDll,
            TempStrNoSize("\x10""xlFittingRSquare"),
            TempStrNoSize("\x04""BCP#"),
            TempStrNoSize("\x21""FITTING.COEFFICIENT.DETERMINATION"),
            TempStrNoSize("\x23""nom de la courbe à analyser,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x1C""xlObjectTools - Yield Curve"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x9C""Cette fonction fournit le coefficient de détermination pour une courbe du type NSS (somme des carrés des résidus pondérés par lse durations des instruments)"),
            TempStrNoSize("\x1E""Le nom de la courbe à analyser"),
            TempStrNoSize("\x21""Un déclencheur pour le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x10""xlFittingRSquare")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }