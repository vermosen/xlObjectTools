/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/03/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateInterestRateSwap(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateInterestRateSwap
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x23""xlInitiateInterestRateSwap"),
            TempStrNoSize("\x08""PCCCLP#"),
            TempStrNoSize("\x1B""INSTANCE.INTEREST.RATE.SWAP"),
            TempStrNoSize("\x79""identifiant de l'instrument,identifiants de la jambe fixe,identifiant de la jambe variable,payeur fixe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x42""Cette fonction instancie un swap à partir des jambes selectionnées"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x1E""L'identifiant de la jambe fixe"),
            TempStrNoSize("\x22""L'identifiant de la jambe variable"),
            TempStrNoSize("\x22""Indique si le swap est payeur fixe"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateInterestRateSwap(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // libère la fonction xlInitiateInterestRateSwap
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x23""xlInitiateInterestRateSwap"),
            TempStrNoSize("\x08""PCCCLP#"),
            TempStrNoSize("\x1B""INSTANCE.INTEREST.RATE.SWAP"),
            TempStrNoSize("\x79""identifiant de l'instrument,identifiants de la jambe fixe,identifiant de la jambe variable,payeur fixe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x42""Cette fonction instancie un swap à partir des jambes selectionnées"),
            TempStrNoSize("\x19""L'identifiant de l'object"),
            TempStrNoSize("\x1E""L'identifiant de la jambe fixe"),
            TempStrNoSize("\x22""L'identifiant de la jambe variable"),
            TempStrNoSize("\x22""Indique si le swap est payeur fixe"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x23""xlInitiateInterestRateSwap")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }