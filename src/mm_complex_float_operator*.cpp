#include "dense.hpp"

template<>
matrix<std::complex<float>> matrix<std::complex<float>>:: operator*(matrix<std::complex<float>> const& A){
    matrix<std::complex<float>> B((*this).dim_size[0], A.dim_size[1]);
    std::complex<float> a(1, 0);
    std::complex<float> b(0, 0);
    cblas_cgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], &a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], &b, B.values.data(), B.precomputed_strides[0]);
    return B;
}
template class matrix<std::complex<float>>;