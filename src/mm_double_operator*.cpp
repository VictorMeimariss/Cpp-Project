#include "dense.hpp"

template<>
matrix<double> matrix<double>:: operator*(matrix<double> const& A){
    matrix<double> B((*this).dim_size[0], A.dim_size[1]);
    double a = 1;
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], 0, B.values.data(), B.precomputed_strides[0]);
    return B;
}
template class matrix<double>;