/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlKalmanFilter(const XLOPER & xDll) {

             // Enregistre la fonction xlKalmanFilter
        Excel(xlfRegister, 0, 11, & xDll,
            TempStrNoSize("\x0E""xlKalmanFilter"),
            TempStrNoSize("\x04""PPP#"),
            TempStrNoSize("\x16""INSTANCE.FILTRE.KALMAN"),
            TempStrNoSize("\x18""plage des séries,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x03""N/A"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

    }

inline void unregisterxlKalmanFilter(const XLOPER & xDll) {

        XLOPER xlRegID ;

             // Enregistre la fonction xlKalmanFilter
        Excel(xlfRegister, 0, 11, & xDll,
            TempStrNoSize("\x0E""xlKalmanFilter"),
            TempStrNoSize("\x04""PPP#"),
            TempStrNoSize("\x16""INSTANCE.FILTRE.KALMAN"),
            TempStrNoSize("\x18""plage des séries,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x15""xlObjectTools - Math"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x03""N/A"),
            TempStrNoSize("\x17""Déclenche le recalcul  ")) ;

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x0E""xlKalmanFilter")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }