#include "dense.hpp"

template <typename U>
matrix<std::complex<double>> operator*(U x, const matrix<std::complex<double>>& A){
    matrix<std::complex<double>> B = A;
    cblas_zscal(B.get_size(), &x, B.get_values_data(), 1);
    return B;
}
template matrix<std::complex<double>> operator*(int x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(float x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(double x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(std::complex<float> x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(std::complex<double> x, const matrix<std::complex<double>>&);