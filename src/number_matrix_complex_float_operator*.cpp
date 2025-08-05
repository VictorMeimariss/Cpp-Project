#include "dense.hpp"

template <typename U>
matrix<std::complex<float>> operator*(U x, const matrix<std::complex<float>>& A){
    matrix<std::complex<float>> B = A;
    cblas_cscal(B.get_size(), &x, B.get_values_data(), 1);
    return B;
}
template matrix<std::complex<float>> operator*(int x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(float x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(double x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(std::complex<float> x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(std::complex<double> x, const matrix<std::complex<float>>&);