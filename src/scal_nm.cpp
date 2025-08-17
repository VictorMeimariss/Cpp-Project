#include "dense.hpp"

template <typename T, typename U>
matrix<T> operator*(U x, const matrix<T>& A){
    matrix<T> B = A;

    if constexpr (std::is_same_v<T, float>)
        sscal(B.get_size(), x, B.get_values_data(), 1);
    else if constexpr (std::is_same_v<T, double>)
        dscal(B.get_size(), x, B.get_values_data(), 1);
    else if constexpr (std::is_same_v<T, std::complex<float>>)
        cscal(B.get_size(), &x, B.get_values_data(), 1);
    else if constexpr (std::is_same_v<T, std::complex<double>>)
        zscal(B.get_size(), &x, B.get_values_data(), 1);
    return B;
}
template matrix<float> operator*(int x, const matrix<float>&);
template matrix<float> operator*(float x, const matrix<float>&);
template matrix<float> operator*(double x, const matrix<float>&);

template matrix<double> operator*(int x, const matrix<double>&);
template matrix<double> operator*(float x, const matrix<double>&);
template matrix<double> operator*(double x, const matrix<double>&);

template matrix<std::complex<float>> operator*(int x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(float x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(double x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(std::complex<float> x, const matrix<std::complex<float>>&);
template matrix<std::complex<float>> operator*(std::complex<double> x, const matrix<std::complex<float>>&);

template matrix<std::complex<double>> operator*(int x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(float x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(double x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(std::complex<float> x, const matrix<std::complex<double>>&);
template matrix<std::complex<double>> operator*(std::complex<double> x, const matrix<std::complex<double>>&);