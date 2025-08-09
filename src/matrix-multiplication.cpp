#include "../inc/dense.hpp"
template<typename T>
void matrix<T>::matrix_multiplication(const CBLAS_TRANSPOSE transa, const CBLAS_TRANSPOSE transb,const T beta, matrix<T> const& A, matrix<T> const &B, matrix<T> &C, const T alpha){
    if constexpr (std::is_same_v<T, float>)
        cblas_sgemm(CblasRowMajor, transa,transb,(MKL_INT)A.dim_size[0],(MKL_INT)B.dim_size[1],(MKL_INT)A.dim_size[1],alpha,A.v_data(),(MKL_INT)A.dim_size[1],B.v_data(),(MKL_INT)B.dim_size[1],beta,C.v_data(),(MKL_INT)C.dim_size[1]);
    else if constexpr (std::is_same_v<T,double>)
        cblas_dgemm(CblasRowMajor, transa,transb,(MKL_INT)A.dim_size[0],(MKL_INT)B.dim_size[1],(MKL_INT)A.dim_size[1],alpha,A.v_data(),(MKL_INT)A.dim_size[1],B.v_data(),(MKL_INT)B.dim_size[1],beta,C.v_data(),(MKL_INT)C.dim_size[1]);
    else if constexpr (std::is_complex_v<T> && sizeof(T)==sizeof(std::complex<float>))
        cblas_cgemm(CblasRowMajor, transa,transb,(MKL_INT)A.dim_size[0],(MKL_INT)B.dim_size[1],(MKL_INT)A.dim_size[1],reinterpret_cast<const void*>(&alpha),A.v_data(),(MKL_INT)A.dim_size[1],B.v_data(),(MKL_INT)B.dim_size[1],reinterpret_cast<const void*>(&beta),C.v_data(),(MKL_INT)C.dim_size[1]);
    else if constexpr (std::is_complex_v<T> && sizeof(T)==sizeof(std::complex<double>))
        cblas_zgemm(CblasRowMajor, transa,transb,(MKL_INT)A.dim_size[0],(MKL_INT)B.dim_size[1],(MKL_INT)A.dim_size[1],reinterpret_cast<const void*>(&alpha),A.v_data(),(MKL_INT)A.dim_size[1],B.v_data(),(MKL_INT)B.dim_size[1],reinterpret_cast<const void*>(&beta),C.v_data(),(MKL_INT)C.dim_size[1]);
}
template void matrix<float>: matrix_multiplication(const CBLAS_TRANSPOSE, const CBLAS_TRANSPOSE, const float, const matrix<float>&, const matrix<float>&, const matrix<float>&, const float);
template void matrix<double>: matrix_multiplication(const CBLAS_TRANSPOSE, const CBLAS_TRANSPOSE, const double, const matrix<double>&, const matrix<double>&, const matrix<double>&, const double);
template void matrix<std::complex<float>>: matrix_multiplication(const CBLAS_TRANSPOSE, const CBLAS_TRANSPOSE, const std::complex<float>, const matrix<std::complex<float>>&, const matrix<std::complex<float>>&, const matrix<std::complex<float>>&, const std::complex<float>);
template void matrix<std::complex<double>>: matrix_multiplication(const CBLAS_TRANSPOSE, const CBLAS_TRANSPOSE, const std::complex<double>, const matrix<std::complex<double>>&, const matrix<std::complex<double>>&, const matrix<std::complex<double>>&, const std::complex<double>);
