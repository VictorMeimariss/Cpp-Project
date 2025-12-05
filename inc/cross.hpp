#ifndef CROSS_HPP
#define CROSS_HPP
#include <cstring> 
/**
 * @file cross.hpp
 * @brief Header file for the cross product functions of dense and sparse matrices.
 */

#include "dense.hpp"
#include "sparse.hpp"
#include <mkl.h>

namespace dense{
/**
* @brief Operator *, multiplies two 2D dense and sparse matrices returning a dense matrix
* @param A A constant matrix reference used after the operator
* @param B A constant matrix reference used after the operator
*/
template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B); // Victor
template<typename T>
std::vector<T> LU_solver (dense::matrix<T>& A,std::vector<T> b){
    if (A.get_dim_size(1)!=A.get_dim_size(0)){
        throw std::invalid_argument("Can only solve square matrices");
    }
    lapack_int info;
    lapack_int r = A.get_dim_size(0);
    lapack_int * ipiv = new lapack_int[r];

    size_t mem1 = r*r*sizeof(T);
    T* A_data = (T*) mkl_malloc(mem1, 64);
    memcpy(A_data, A.get_values_data(), mem1);

    size_t mem2 = b.size()*sizeof(T);
    T* b_data = (T*) mkl_malloc(mem2, 64);
    memcpy(b_data, b.data(), mem2);

    if constexpr (std::is_same_v<T, float>){
    info = LAPACKE_sgetrf (LAPACK_ROW_MAJOR , r , r, A_data ,r , ipiv);
    info = LAPACKE_sgetrs(LAPACK_ROW_MAJOR, 'N', r, 1, A_data, r, ipiv, b_data, 1);
    }
    else if constexpr (std::is_same_v<T, double>){
    info = LAPACKE_dgetrf (LAPACK_ROW_MAJOR , r , r, A_data ,r , ipiv);
    info = LAPACKE_dgetrs(LAPACK_ROW_MAJOR, 'N', r, 1, A_data, r, ipiv, b_data, 1);
    }
    else if constexpr (std::is_same_v<T, std::complex<float>>){
    info = LAPACKE_cgetrf (LAPACK_ROW_MAJOR , r , r, reinterpret_cast<MKL_Complex8*> (A_data) ,r , ipiv);
    info = LAPACKE_cgetrs(LAPACK_ROW_MAJOR, 'N', r, 1, reinterpret_cast<MKL_Complex8*> (A_data), r, ipiv, reinterpret_cast<MKL_Complex8*> (b_data), 1);
    }
    else if constexpr (std::is_same_v<T, std::complex<double>>){
    info = LAPACKE_zgetrf (LAPACK_ROW_MAJOR , r , r, reinterpret_cast<MKL_Complex16*> (A_data) ,r , ipiv);
    info = LAPACKE_zgetrs(LAPACK_ROW_MAJOR, 'N', r, 1, reinterpret_cast<MKL_Complex16*> (A_data), r, ipiv, reinterpret_cast<MKL_Complex16*> (b_data), 1);
    }
    std::vector<T> ret(b_data, b_data + r);
    mkl_free(A_data);
    mkl_free(b_data);  
    return ret;
}
}

namespace sparse{
/**
* @brief Operator *, multiplies two 2D sparse and dense matrices returning a dense matrix
* @param A A constant matrix reference used after the operator
* @param B A constant matrix reference used after the operator
*/
template<typename T>
dense::matrix<T> operator*(const sparse::matrix<T>& B, const dense::matrix<T>& A);// Victor
}

#endif
