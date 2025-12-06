#include "dense.hpp"
#include <cstring> 

namespace dense{
template <typename T>
std::vector<T> LU_solver (dense::matrix<T>& A, std::vector<T> b){
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

template std::vector<float> LU_solver(dense::matrix<float>&, std::vector<float> b);
template std::vector<double> LU_solver(dense::matrix<double>&, std::vector<double> b);
template std::vector<std::complex<float>> LU_solver(dense::matrix<std::complex<float>>&, std::vector<std::complex<float>> b);
template std::vector<std::complex<double>> LU_solver(dense::matrix<std::complex<double>>&, std::vector<std::complex<double>> b);
}