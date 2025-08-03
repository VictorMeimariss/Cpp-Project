#include "dense.hpp"

template<>
matrix<std::complex<double>> matrix<std::complex<double>>:: operator*(matrix<std::complex<double>> const& A){
    matrix<std::complex<double>> B((*this).dim_size[0], A.dim_size[1]);
    std::complex<double> a(1, 0);
    std::complex<double> b(0, 0);
    cblas_zgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], &a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], &b, B.values.data(), B.precomputed_strides[0]);
    return B;
}
template class matrix<std::complex<double>>;