/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 11/02/11
 *  Copyright 2009. All rights reserved.
 *
 */

#include <xlsdk/xlsdkdefines.hpp>

inline void registerxlInitiateSwaptionHelper(const XLOPER & xDll) {

		// registers the function xlInitiateSwaptionHelper
		Excel(xlfRegister, 0, 22, &xDll,
			TempStrNoSize("\x18""xlInitiateSwaptionHelper"),
			TempStrNoSize("\x0F""PCEEECPPPCPPPP#"),
			TempStrNoSize("\x29""OBJECT.VOLATILITY.SURFACE.SWAPTION.HELPER"),
			TempStrNoSize("\x8F""identifier,exercice,maturity,volatility,index,fixed leg tenor,fixed leg daycounter,float leg daycounter,curve,error type,strike,nominal,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x16""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x57""This function instanciates a swaption helper for volatility surface calibration purpose"),
			TempStrNoSize("\x1A""The name of the instrument"),
			TempStrNoSize("\x11""The exercice date"),
			TempStrNoSize("\x0C""The end date"),
			TempStrNoSize("\x15""The quoted volatility"),
			TempStrNoSize("\x10""The fixing index"),
			TempStrNoSize("\x13""The fixed leg tenor"),
			TempStrNoSize("\x18""The fixed leg daycounter"),
			TempStrNoSize("\x1B""The floating leg daycounter"),
			TempStrNoSize("\x0F""The yield curve"),
			TempStrNoSize("\x3D""The calibration Error type (defaults to relative price error)"),
			TempStrNoSize("\x1A""The strike rate (optional)"),
			TempStrNoSize("\x16""The nominal (optional)"));


    }

inline void unregisterxlInitiateSwaptionHelper(const XLOPER & xDll) {

        XLOPER xlRegID ;

		// unregister the function xlInitiateSwaptionHelper
		Excel(xlfRegister, 0, 22, &xDll,
			TempStrNoSize("\x18""xlInitiateSwaptionHelper"),
			TempStrNoSize("\x0F""PCEEECCCCCPPPP#"),
			TempStrNoSize("\x29""OBJECT.VOLATILITY.SURFACE.SWAPTION.HELPER"),
			TempStrNoSize("\x8F""identifier,exercice,maturity,volatility,index,fixed leg tenor,fixed leg daycounter,float leg daycounter,curve,error type,strike,nominal,trigger"),
			TempStrNoSize("\x01""1"),
			TempStrNoSize("\x16""xlObjectTools - Object"),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x00"""),
			TempStrNoSize("\x57""This function instanciates a swaption helper for volatility surface calibration purpose"),
			TempStrNoSize("\x1A""The name of the instrument"),
			TempStrNoSize("\x11""The exercice date"),
			TempStrNoSize("\x0C""The end date"),
			TempStrNoSize("\x15""The quoted volatility"),
			TempStrNoSize("\x10""The fixing index"),
			TempStrNoSize("\x13""The fixed leg tenor"),
			TempStrNoSize("\x18""The fixed leg daycounter"),
			TempStrNoSize("\x1B""The floating leg daycounter"),
			TempStrNoSize("\x0F""The yield curve"),
			TempStrNoSize("\x3D""The calibration Error type (defaults to relative price error)"),
			TempStrNoSize("\x1A""The strike rate (optional)"),
			TempStrNoSize("\x16""The nominal (optional)"));

        Excel4(xlfRegisterId, & xlRegID, 2, & xDll,
            TempStrNoSize("\x1D""xlInitiateSwaptionHelper")) ;

        Excel4(xlfUnregister, 0, 1, & xlRegID) ;

    }