/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_all_hpp
#define register_all_hpp

#include <xlsdk/xlsdkdefines.hpp>
#include <xlFunction/math/register_math.hpp>
#include <xlFunction/curve/register_curve.hpp>
#include <xlFunction/bond/register_bond.hpp>
#include <xlFunction/calendar/register_calendar.hpp>
#include <xlFunction/object/register_object.hpp>
#include <xlFunction/swap/register_swap.hpp>
#include <xlFunction/experimental/register_experimental.hpp>
#include <xlFunction/addin/register_addin.hpp>

inline void registerAll(const XLOPER & xDll) {

            // register xll menu
        register_calendar		(xDll);
        register_math			(xDll);
        register_yieldCurve		(xDll);
        register_object			(xDll);
        register_swap			(xDll);
        register_bond			(xDll);
        register_experimental	(xDll);
        register_addin			(xDll);

    }

inline void unregisterAll(const XLOPER & xDll) {

            // unregister xll menu
        unregister_calendar		(xDll);
        unregister_math			(xDll);
        unregister_yieldCurve	(xDll);
        unregister_object		(xDll);
        unregister_swap			(xDll);
        unregister_bond			(xDll);
        unregister_experimental (xDll);
        unregister_addin        (xDll);

    }

#endif
