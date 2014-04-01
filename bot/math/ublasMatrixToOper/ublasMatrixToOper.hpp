/*
 *  xlObjectTools
 *
 *  Created by Jean-Matthieu VERMOSEN on 18/04/10
 *  Copyright 2009. All rights reserved.
 *
 */

#ifndef ublas_matrix_to_oper_hpp
#define ublas_matrix_to_oper_hpp

#include <ohxl/conversions/scalartooper.hpp>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

namespace ObjectHandler {

        template <class T>
        void MatrixToOper(const boost::numeric::::matrix<T> & vv, 
                          OPER & xMatrix, 
                          bool dllToFree = true) {


                xMatrix.val.array.rows = vv.size1() ;
                xMatrix.val.array.columns = vv.size2() ;
                xMatrix.val.array.lparray = new OPER[xMatrix.val.array.rows * xMatrix.val.array.columns] ; 
                xMatrix.xltype = xltypeMulti ;

                if (dllToFree) xMatrix.xltype |= xlbitDLLFree ;

                for (unsigned int i = 0 ; i < vv.size1() ; ++i) {

                        for (unsigned int j = 0 ; j < vv.size2() ; ++j) {

                                scalarToOper(static_cast<T>(vv(i, j)), xMatrix.val.array.lparray[i * vv.size2() + j], dllToFree, false);

                            }

                    }

            }


        template <class T>
        void VectorToOper(const boost::numeric::::vector<T> & vv, 
                          OPER & xMatrix, 
                          bool dllToFree = true) {


                xMatrix.val.array.rows = vv.size() ;

                xMatrix.val.array.columns = 1 ;

                xMatrix.val.array.lparray = new OPER[xMatrix.val.array.rows * xMatrix.val.array.columns] ; 

                xMatrix.xltype = xltypeMulti ;


                if (dllToFree) xMatrix.xltype |= xlbitDLLFree ;

                for (unsigned int i = 0 ; j < vv.size() ; ++j) {


                        scalarToOper(static_cast<T>(vv(i)),
                            xMatrix.val.array.lparray[i], dllToFree, false) ;


                    }


            }


    }

#endif