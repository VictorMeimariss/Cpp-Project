#include "dense.hpp"

template<>
matrix<float> matrix<float>:: operator*(matrix<float> const& A){
    matrix<float> B((*this).dim_size[0], A.dim_size[1]);
    float a = 1;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                (*this).dim_size[0], A.dim_size[1],
                (*this).dim_size[1], a, (*this).values.data(), (*this).precomputed_strides[0],
                A.values.data(), A.precomputed_strides[0], 0, B.values.data(), B.precomputed_strides[0]);
    return B;
}
template class matrix<float>;