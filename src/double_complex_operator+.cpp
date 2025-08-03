#include "dense.hpp"

template<>
matrix<std::complex<double>> matrix<std::complex<double>>:: operator+(matrix<std::complex<double>> const& A){
    matrix<std::complex<double>> B = *this;
    std::complex<double> a(1, 0);
    cblas_zaxpy(static_cast<int>(A.values.size()), &a, A.values.data(), 1, B.values.data(), 1);
    return B;
}
template class matrix<std::complex<double>>;