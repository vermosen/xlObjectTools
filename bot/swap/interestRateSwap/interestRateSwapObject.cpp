/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 25/07/10
 *  Copyright 2009. All rights reserved.
 *
 */

#include <bot/swap/interestRateSwap/interestRateSwapObject.hpp>

namespace QuantLibAddin {


        interestRateSwapObject::interestRateSwapObject(
            boost::shared_ptr<ValueObjects::interestRateSwapValueObject> & valueObject,
            boost::shared_ptr<Leg> & fixedLeg,
            boost::shared_ptr<Leg> & floatLeg,
            const QuantLibExtended::interestRateSwap::Type & type,
            const bool & permanent) :

                Instrument(valueObject, permanent) {


                    boost::shared_ptr<QuantLib::Leg> fxdLeg ;

                    fixedLeg->getLibraryObject(fxdLeg) ;

                    boost::shared_ptr<QuantLib::Leg> floLeg ;

                    floatLeg->getLibraryObject(floLeg) ;

                    libraryObject_ = boost::shared_ptr<QuantLib::Instrument>(new
                        QuantLibExtended::interestRateSwap(* fxdLeg, 
                                                           * floLeg, 
                                                           type)) ;
                

                } ;

            long interestRateSwapObject::getLegRank(const std::string & legId_) const {


                    long legRank = -1 ;

                    std::string nameUpper = boost::algorithm::to_upper_copy(legId_) ;

                    std::vector<std::string> myLegId = ObjectHandler::vector::convert2<std::string>(this->propertyValue("LEGIDS"), "LEGIDS") ;

                    for (unsigned long i = 0 ; i < myLegId.size() ; i++) {
                        

                            if (myLegId[i] == legId_) legRank = i ;
                        
                        
                        }

                    QL_REQUIRE(legRank >= 0, "unknown leg Id")

                    return legRank ;


                } ;

            std::string interestRateSwapObject::getLegType(const QuantLib::Natural & legRank_) const {

                    std::vector<std::string> myLegType = 
                        ObjectHandler::vector::convert2<std::string>(this->propertyValue("LEGTYPES"), "LEGTYPES") ;

                    QL_REQUIRE(legRank_ + 1 < myLegType.size() , "")

                    return myLegType[legRank_] ;  


                } ;

            std::string interestRateSwapObject::getLegType(const std::string & legId_) const {


                    return this->getLegType(static_cast<QuantLib::Natural>(this->getLegRank(legId_))) ;


                } ;


    }