/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateZeroCouponInflationSwapUnitedStates(const XLOPER & xDll) {

             // Enregistre la fonction xlInitiateZeroCouponInflationSwapUnitedStates
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x2D""xlInitiateZeroCouponInflationSwapUnitedStates"),
            TempStrNoSize("\x07""PCCCLP#"),
            TempStrNoSize("\x31""INSTANCE.SWAP.INFLATION.ZERO.COUPON.UNITED.STATES"),
            TempStrNoSize("\x6F""identifiant de l'instrument,identifiants de la jambe fixe,identifiant de la jambe inflation,payeur fixe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x41""Cette fonction instancie un swap inflation zéro-coupon en dollar."),
            TempStrNoSize("\x15""L'identifiant du swap"),
            TempStrNoSize("\x1E""L'identifiant de la jambe fixe"),
            TempStrNoSize("\x23""L'identifiant de la jambe inflation"),
            TempStrNoSize("\x0D""payeur fixe ?"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlInitiateZeroCouponInflationSwapUnitedStates(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlInitiateZeroCouponInflationSwapUnitedStates
        Excel(xlfRegister, 0, 15, & xDll,
            TempStrNoSize("\x2D""xlInitiateZeroCouponInflationSwapUnitedStates"),
            TempStrNoSize("\x07""PCCCLP#"),
            TempStrNoSize("\x31""INSTANCE.SWAP.INFLATION.ZERO.COUPON.UNITED.STATES"),
            TempStrNoSize("\x6F""identifiant de l'instrument,identifiants de la jambe fixe,identifiant de la jambe inflation,payeur fixe,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x41""Cette fonction instancie un swap inflation zéro-coupon en dollar."),
            TempStrNoSize("\x15""L'identifiant du swap"),
            TempStrNoSize("\x1E""L'identifiant de la jambe fixe"),
            TempStrNoSize("\x23""L'identifiant de la jambe inflation"),
            TempStrNoSize("\x0D""payeur fixe ?"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x2D""xlInitiateZeroCouponInflationSwapUnitedStates")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }