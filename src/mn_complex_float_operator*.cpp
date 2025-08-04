#include "dense.hpp"

template <>
matrix<std::complex<float>> operator*(std::complex<float> x, const matrix<std::complex<float>>& A){
    matrix<std::complex<float>> B = A;
    cblas_cscal(B.get_size(), &x, B.get_values_data(), 1);
    return B;
}
template class matrix<std::complex<float>>;