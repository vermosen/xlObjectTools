/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_bond_hpp
#define register_bond_hpp

#include <xlsdk/xlsdkdefines.hpp>

#include <xlFunction/bond/xlZSpreadFromPrice/register_xlZSpreadFromPrice.hpp>
#include <xlFunction/bond/xlInstrumentDV01/register_xlInstrumentDV01.hpp>
#include <xlFunction/bond/xlInstrumentCarry/register_xlInstrumentCarry.hpp>
#include <xlFunction/bond/xlInstrumentAccruedAmount/register_xlInstrumentAccruedAmount.hpp>
#include <xlFunction/bond/xlPriceFromZSpread/register_xlPriceFromZSpread.hpp>
#include <xlFunction/bond/xlIsActiveInstrument/register_xlIsActiveInstrument.hpp>
#include <xlFunction/bond/xlGetCashFlowDates/register_xlGetCashFlowDates.hpp>
#include <xlFunction/bond/xlInstrumentConvexity/register_xlInstrumentConvexity.hpp>
#include <xlFunction/bond/xlInstrumentPrice/register_xlInstrumentPrice.hpp>
#include <xlFunction/bond/xlInstrumentDuration/register_xlInstrumentDuration.hpp>
#include <xlFunction/bond/xlInstrumentSettlementDate/register_xlInstrumentSettlementDate.hpp>
#include <xlFunction/bond/xlInstrumentYield/register_xlInstrumentYield.hpp>
#include <xlFunction/bond/xlInstrumentFlowCount/register_xlInstrumentFlowCount.hpp>
#include <xlFunction/bond/xlInstrumentNextCashFlowDate/register_xlInstrumentNextCashFlowDate.hpp>
#include <xlFunction/bond/xlInstrumentPreviousCashFlowDate/register_xlInstrumentPreviousCashFlowDate.hpp>
#include <xlFunction/bond/xlInstrumentNextCashFlowAmount/register_xlInstrumentNextCashFlowAmount.hpp>
#include <xlFunction/bond/xlInstrumentPreviousCashFlowAmount/register_xlInstrumentPreviousCashFlowAmount.hpp>
#include <xlFunction/bond/xlInstrumentCostOfCarry/register_xlInstrumentCostOfCarry.hpp>
#include <xlFunction/bond/xlInstrumentRollDown/register_xlInstrumentRollDown.hpp>

inline void register_bond(const XLOPER & xDll) {


            // register bond functions
        registerxlZSpreadFromPrice(xDll) ;
        registerxlInstrumentDV01(xDll) ;        
        registerxlInstrumentCarry(xDll) ;
        registerxlInstrumentAccruedAmount(xDll) ;        
        registerxlPriceFromZSpread(xDll) ;        
        registerxlIsActiveInstrument(xDll) ;
        registerxlGetCashFlowDates(xDll) ;
        registerxlInstrumentConvexity(xDll) ;
        registerxlInstrumentPrice(xDll) ;
        registerxlInstrumentDuration(xDll) ;
        registerxlInstrumentRollDown(xDll) ;
        registerxlInstrumentSettlementDate(xDll) ;
        registerxlInstrumentYield(xDll) ;
        registerxlInstrumentFlowCount(xDll) ;
        registerxlInstrumentNextCashFlowDate(xDll) ;
        registerxlInstrumentPreviousCashFlowDate(xDll) ;
        registerxlInstrumentNextCashFlowAmount(xDll) ;
        registerxlInstrumentPreviousCashFlowAmount(xDll) ;
        registerxlInstrumentCostOfCarry(xDll) ;

    } ;

inline void unregister_bond(const XLOPER & xDll) {
    

            // unregister bond functions
        unregisterxlZSpreadFromPrice(xDll) ;
        
        unregisterxlInstrumentDV01(xDll) ;
        
        unregisterxlInstrumentCarry(xDll) ;
        
        unregisterxlInstrumentAccruedAmount(xDll) ;
        
        unregisterxlPriceFromZSpread(xDll) ;
        
        unregisterxlIsActiveInstrument(xDll) ;
        
        unregisterxlGetCashFlowDates(xDll) ;
        
        unregisterxlInstrumentConvexity(xDll) ;
        
        unregisterxlInstrumentPrice(xDll) ;
        
        unregisterxlInstrumentDuration(xDll) ;
        
        unregisterxlInstrumentRollDown(xDll) ;
        
        unregisterxlInstrumentSettlementDate(xDll) ;
        
        unregisterxlInstrumentYield(xDll) ;
        
        unregisterxlInstrumentFlowCount(xDll) ;
        
        unregisterxlInstrumentNextCashFlowDate(xDll) ;
        
        unregisterxlInstrumentPreviousCashFlowDate(xDll) ;
        
        unregisterxlInstrumentNextCashFlowAmount(xDll) ;
        
        unregisterxlInstrumentPreviousCashFlowAmount(xDll) ;

        unregisterxlInstrumentCostOfCarry(xDll) ;


    } ;


#endif
