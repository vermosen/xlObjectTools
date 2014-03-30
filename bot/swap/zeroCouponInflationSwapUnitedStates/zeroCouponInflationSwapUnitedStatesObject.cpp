/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 29/08/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/swap/zeroCouponInflationSwapUnitedStates/zeroCouponInflationSwapUnitedStatesObject.hpp>

namespace QuantLibAddin {


        zeroCouponInflationSwapUnitedStatesObject::zeroCouponInflationSwapUnitedStatesObject(
            boost::shared_ptr<ValueObjects::zeroCouponInflationSwapUnitedStatesValueObject> & valueObject,
            boost::shared_ptr<Leg> & leg1,
            boost::shared_ptr<Leg> & leg2,
            const bool & payFixed,
            const bool & permanent) :
            
            Swap(valueObject, permanent) {


                    boost::shared_ptr<QuantLib::Leg> fxdLeg ;

                    leg1->getLibraryObject(fxdLeg) ;

                    boost::shared_ptr<QuantLib::Leg> floLeg ;

                    leg2->getLibraryObject(floLeg) ;

                    libraryObject_ = boost::shared_ptr<QuantLib::Instrument>(new
                        QuantLibExtended::zeroCouponInflationSwapUnitedStates(* fxdLeg, 
                                                                              * floLeg, 
                                                                              payFixed)) ;
                

                } ;

            long zeroCouponInflationSwapUnitedStatesObject::getLegRank(const std::string & legId_) const {


                    long legRank = -1 ;

                    std::string nameUpper = boost::algorithm::to_upper_copy(legId_) ;

                    std::vector<std::string> myLegId = ObjectHandler::vector::convert2<std::string>(this->propertyValue("LEGIDS"), "LEGIDS") ;

                    for (unsigned long i = 0 ; i < myLegId.size() ; i++) {
                        

                            if (myLegId[i] == legId_) legRank = i ;
                        
                        
                        }

                    QL_REQUIRE(legRank >= 0, "unknown leg Id")

                    return legRank ;
                    
                
                } ;

            std::string zeroCouponInflationSwapUnitedStatesObject::getLegType(const QuantLib::Natural & legRank_) const {

                    std::vector<std::string> myLegType = 
                        ObjectHandler::vector::convert2<std::string>(this->propertyValue("LEGTYPES"), "LEGTYPES") ;

                    QL_REQUIRE(legRank_ + 1 < myLegType.size() , "")

                    return myLegType[legRank_] ;


                } ;

            std::string zeroCouponInflationSwapUnitedStatesObject::getLegType(const std::string & legId_) const {


                    return this->getLegType(static_cast<QuantLib::Natural>(this->getLegRank(legId_))) ;


                } ;


    }