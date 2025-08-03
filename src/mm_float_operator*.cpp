#include "dense.hpp"

template<>
matrix<float> matrix<float>:: operator*(matrix<float> const& A){
    matrix<float> B = *this;
    float a = 1;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, B.precomputed_strides[1], A.precomputed_strides[0], B.precomputed_strides[0], a,);
    //cblas_saxpy(static_cast<int>(A.values.size()), a, A.values.data(), 1, B.values.data(), 1);
    return B;
}
template class matrix<float>;