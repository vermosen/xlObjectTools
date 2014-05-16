/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateIborIndex(const XLOPER & xDll) {

        // Declare the xlInitiateIborIndex function
        Excel(xlfRegister, 0, 19, & xDll,
            TempStrNoSize("\x13""xlInitiateIborIndex"),
            TempStrNoSize("\x0B""CCCCECPPCP#"),
            TempStrNoSize("\x11""OBJECT.IBOR.INDEX"),
            TempStrNoSize("\x85""objet identifier,fixing historical series,tenor,settlement days,calendar,business days convention,end of month,daycount basis,trigger"),
            TempStrNoSize("\x01""1"),
            TempStrNoSize("\x17""xlObjectTools - Object"),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x00"""),
            TempStrNoSize("\x2A""This function creates an ibor index object"),
            TempStrNoSize("\x11""Object Identifer"),
            TempStrNoSize("\x1C""The fixing series identifier"),
            TempStrNoSize("\x12""The index maturity"),
            TempStrNoSize("\x1D""The number of settlement days"),
			TempStrNoSize("\x14""Calendar for fixings"),
			TempStrNoSize("\x17""Business day convention"),
			TempStrNoSize("\x11""End-of-month rule"),
			TempStrNoSize("\x15""Annual Daycount Basis"),
            TempStrNoSize("\x1B""Trigger for recalculation  ")) ;

    }

inline void unregisterxlInitiateIborIndex(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// Frees the xlInitiateIborIndex function
		Excel(xlfRegister, 0, 19, &xDll,
			TempStrNoSize("\x13""xlInitiateIborIndex"),
			TempStrNoSize("\x0B""CCCCECPPCP#"),
			TempStrNoSize("\x11""OBJECT.IBOR.INDEX"),
			TempStrNoSize("\x85""objet identifier,fixing historical series,tenor,settlement days,calendar,business days convention,end of month,daycount basis,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x17""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x2A""This function creates an ibor index object"),
			TempStrNoSize("\x11""Object Identifer"),
			TempStrNoSize("\x1C""The fixing series identifier"),
			TempStrNoSize("\x12""The index maturity"),
			TempStrNoSize("\x1D""The number of settlement days"),
			TempStrNoSize("\x14""Calendar for fixings"),
			TempStrNoSize("\x17""Business day convention"),
			TempStrNoSize("\x11""End-of-month rule"),
			TempStrNoSize("\x15""Annual Daycount Basis"),
			TempStrNoSize("\x1B""Trigger for recalculation  "));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x13""xlInitiateIborIndex")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }