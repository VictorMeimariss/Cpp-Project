#include "dense.hpp"

template <typename T, typename U>
matrix<T> operator*(U x, const matrix<double>& A){
    x = static_cast<double>(x);
    matrix<double> B = A;
    cblas_dscal(B.get_size(), x, B.get_values_data(), 1);
    return B;
}
//template matrix<double> operator*<double, int>(int, const matrix<double>&);
//template matrix<double> operator*<double, float>(float, const matrix<double>&);
//template matrix<double> operator*<double, double>(double, const matrix<double>&);
//template matrix<double> operator*<std::complex<float>>(std::complex<float>, const matrix<double>&);
//template matrix<double> operator*<std::complex<double>>(std::complex<double>, const matrix<double>&);