#include "dense.hpp"

template <>
matrix<std::complex<float>> matrix<std::complex<float>>:: operator*(std::complex<float> x){
    matrix<std::complex<float>> B = *this;
    cblas_cscal(B.values.size(), &x, B.values.data(), 1);
    return B;
}
template class matrix<std::complex<float>>;