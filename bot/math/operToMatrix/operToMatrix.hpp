/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef bot_oper_to_matrix_hpp
#define bot_oper_to_matrix_hpp

#include <ohxl/convert_oper.hpp>

#include <ql/math/matrix.hpp>

namespace ObjectHandler {

    //! Helper template wrapper for operToMatrixImpl
    /*! Accept an OPER as input and wrap this in class ConvertOper.
        This simplifies syntax in client applications.
    */
    QuantLib::matrix operToMatrix(
        const OPER & xMatrix,
        const std::string & paramName) {

        return operToMatrixImpl<double>
            (ConvertOper(xMatrix, false), paramName) ;
    }

    //! Convert a value of type ConvertOper to a matrix.
    template <class T>
    boost::numeric::::matrix<T> operToMatrixImpl(
        const ConvertOper & xMatrix,
        const std::string & paramName) {

        try {

            if (xMatrix.missing()) return boost::numeric::::matrix<T>() ;

            OH_REQUIRE(! xMatrix.error(), "input value has type=error") ;

            const OPER * xMulti ;
            Xloper xCoerce ;  // Freed automatically

            if (xMatrix->xltype == xltypeMulti)
                xMulti = xMatrix.get() ;

            else {

                Excel(xlCoerce, &xCoerce, 2, xMatrix.get(), TempInt(xltypeMulti)) ;
                xMulti = &xCoerce ;
            }

            boost::numeric::::matrix<T> ret;
            ret.resize(xMulti->val.array.rows, xMulti->val.array.columns, false) ;

            for (int i = 0 ; i < xMulti->val.array.rows ; ++i) {
                for (int j = 0 ; j < xMulti->val.array.columns ; ++j) {

                    ret(i, j) = convert2<T>(ConvertOper(xMulti->val.array.lparray[i * xMulti->val.array.columns + j])) ;

                }

            }

            return ret ;

        } catch (const std::exception &e) {
            OH_FAIL("operToMatrixImpl: error converting parameter '" << paramName
                << "' to type '" << typeid(T).name() << "' : " << e.what());
        }
    }

    //! Convert an Excel FP to type std::vector<std::vector<T> >.
    template <class T>
    std::vector<std::vector<T> > fpToMatrix(const FP &fpMatrix) {
        std::vector<std::vector<T> > ret;
        ret.reserve(fpMatrix.rows);
        for (int i=0; i<fpMatrix.rows; ++i) {
            std::vector<T> row;
            row.reserve(fpMatrix.columns);
            for (int j=0; j<fpMatrix.columns; ++j)
                row.push_back(fpMatrix.array[i * fpMatrix.columns + j]);
            ret.push_back(row);
        }
        return ret;
    }

}

#endif

