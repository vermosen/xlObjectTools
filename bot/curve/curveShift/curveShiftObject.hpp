/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 28/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef curve_shift_object_hpp
#define curve_shift_object_hpp

#include <oh/libraryobject.hpp>
#include <bot/curve/curveShift/curveShiftValueObject.hpp>
#include <qle/quotes/gapQuote/gapQuote.hpp>

namespace QuantLibAddin {

    class gapSet : public ObjectHandler::Object { // TODO : remplacer le vecteur de gapQuote par 1 map

        protected :

            OH_OBJ_CTOR(gapSet, ObjectHandler::Object) ;

            std::vector<QuantLib::Handle<QuantLib::gapQuote> > curveShift_ ;

    } ;

    class curveShiftObject : public gapSet {

        public :

            curveShiftObject(boost::shared_ptr<QuantLibAddin::ValueObjects::curveShiftValueObject> & vo,
                             const std::vector<QuantLib::Handle<QuantLib::gapQuote> > & quotes,
                             const bool & permanent = true) ;

            std::vector<QuantLib::Handle<QuantLib::gapQuote> > getcurveShift() const ;

    } ;

}

#endif