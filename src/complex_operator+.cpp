#include "dense.hpp"

template <>
matrix<std::complex<float>> matrix<std::complex<float>>:: operator+(matrix<std::complex<float>> const& A){
    matrix<std::complex<float>> B = *this;
    std::complex<float> a(1, 0);
    cblas_caxpy(static_cast<int>(A.values.size()), &a, A.values.data(), 1, B.values.data(), 1);
    return B;
}
template class matrix<std::complex<float>>;