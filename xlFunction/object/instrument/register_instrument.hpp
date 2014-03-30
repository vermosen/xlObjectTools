/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 31/05/09
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef register_instrument_hpp
#define register_instrument_hpp

#include <xlsdk/xlsdkdefines.hpp>


#include <xlFunction/object/instrument/xlInitiateDeposit/register_xlInitiateDeposit.hpp>

#include <xlFunction/object/instrument/xlInitiateyankeeBond/register_xlInitiateyankeeBond.hpp>

#include <xlFunction/object/instrument/xlInitiateBuNote/register_xlInitiateBuNote.hpp>

#include <xlFunction/object/instrument/xlInitiateBuBill/register_xlInitiateBuBill.hpp>

#include <xlFunction/object/instrument/xlInitiateTreasuryBill/register_xlInitiateTreasuryBill.hpp>

#include <xlFunction/object/instrument/xlInitiateTreasuryNote/register_xlInitiateTreasuryNote.hpp>

#include <xlFunction/object/instrument/xlInitiateAussieNote/register_xlInitiateAussieNote.hpp>

#include <xlFunction/object/instrument/xlInitiateAussieBill/register_xlInitiateAussieBill.hpp>

#include <xlFunction/object/instrument/xlInitiateKangarooBond/register_xlInitiateKangarooBond.hpp>

#include <xlFunction/object/instrument/xlInitiateBtf/register_xlInitiateBtf.hpp>

#include <xlFunction/object/instrument/xlInitiateBtan/register_xlInitiateBtan.hpp>

#include <xlFunction/object/instrument/xlInitiateOat/register_xlInitiateOat.hpp>

#include <xlFunction/object/instrument/xlInitiateDepositFuture/register_xlInitiateDepositFuture.hpp>

inline void register_instrument(const XLOPER & xDll) {
    

                // register instrument
			registerxlInitiateTreasuryNote(xDll) ;
            
			registerxlInitiateTreasuryBill(xDll) ;

            registerxlInitiateBuNote(xDll) ;

            registerxlInitiateBuBill(xDll) ;

            registerxlInitiateAussieNote(xDll) ;

            registerxlInitiateAussieBill(xDll) ;

			registerxlInitiateyankeeBond(xDll) ;
            
			registerxlInitiateDeposit(xDll) ;

            registerxlInitiateKangarooBond(xDll) ;

            registerxlInitiateBtf(xDll) ;
            
			registerxlInitiateBtan(xDll) ;

            registerxlInitiateOat(xDll) ;

            registerxlInitiateDepositFuture(xDll) ;

    
    } ;

inline void unregister_instrument(const XLOPER & xDll) {
    

                // unregister instrument
			unregisterxlInitiateTreasuryNote(xDll) ;
            
			unregisterxlInitiateTreasuryBill(xDll) ;

            unregisterxlInitiateBuNote(xDll) ;

            unregisterxlInitiateBuBill(xDll) ;

            unregisterxlInitiateAussieNote(xDll) ;

            unregisterxlInitiateAussieBill(xDll) ;

			unregisterxlInitiateyankeeBond(xDll) ;
            
			unregisterxlInitiateDeposit(xDll) ;

            unregisterxlInitiateKangarooBond(xDll) ;

            unregisterxlInitiateBtf(xDll) ;
            
			unregisterxlInitiateBtan(xDll) ;

            unregisterxlInitiateOat(xDll) ;

            unregisterxlInitiateDepositFuture(xDll) ;


    } ;


#endif