#include "dense.hpp"

template <>
matrix<std::complex<double>> operator*(std::complex<double> x, const matrix<std::complex<double>>& A){
    matrix<std::complex<double>> B = A;
    cblas_zscal(B.get_size(), &x, B.get_values_data(), 1);
    return B;
}
template class matrix<std::complex<double>>;