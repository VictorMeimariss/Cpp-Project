#include "dense.hpp"

template <>
matrix<std::complex<double>> matrix<std::complex<double>>:: operator*(std::complex<double> x){
    matrix<std::complex<double>> B = *this;
    cblas_zscal(B.values.size(), &x, B.values.data(), 1);
    return B;
}
template class matrix<std::complex<double>>;