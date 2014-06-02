/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSwaptionHelper(const XLOPER & xDll) {

		// register the function xlInitiateSwaptionHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1D""xlInitiateSwaptionHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1B""OBJECT.VOLATILITY.SURFACE.SWAPTION.HELPER"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du titre,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un titre pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x16""L'identifiant du titre"),
            TempStrNoSize("\x10""Le prix du titre"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateSwaptionHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregister the function xlInitiateSwaptionHelper
        Excel(xlfRegister, 0, 14, & xDll,
            TempStrNoSize("\x1D""xlInitiateSwaptionHelper"),
            TempStrNoSize("\x06""PCCEP#"),
            TempStrNoSize("\x1B""INSTANCE.INTERPOLATION.BOND"),
            TempStrNoSize("\x38""Identifiant de l'objet,Identifiant du titre,Prix,Trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x43""Cette fonction instancie un titre pour l'interpolation d'une courbe"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x16""L'identifiant du titre"),
            TempStrNoSize("\x10""Le prix du titre"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1D""xlInitiateBondBootstrapHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }