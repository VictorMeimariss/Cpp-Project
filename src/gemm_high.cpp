#include "dense.hpp"
using namespace dense;

template <typename T>
matrix<T> matrix<T>:: operator*(matrix<T> const& A){
    matrix<T> B((*this).dim_size[0], A.dim_size[1]);

    if constexpr (std::is_same_v<T, float>){
        float a = 1;
        sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], 0, B.values.data(), B.precomputed_strides[0]);}
    else if constexpr (std::is_same_v<T, double>){
        double a = 1;
        dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], 0, B.values.data(), B.precomputed_strides[0]);}
    else if constexpr (std::is_same_v<T, std::complex<float>>){
        std::complex<float> a(1, 0);
        std::complex<float> b(0, 0);
        cgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], &a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], &b, B.values.data(), B.precomputed_strides[0]);}
    else if constexpr (std::is_same_v<T, std::complex<double>>){
        std::complex<double> a(1, 0);
        std::complex<double> b(0, 0);
        zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], &a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], &b, B.values.data(), B.precomputed_strides[0]);}
    return B;
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;