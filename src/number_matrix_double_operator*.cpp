#include "dense.hpp"

template <typename U>
matrix<double> operator*(U x, const matrix<double>& A){
    x = static_cast<double>(x);
    matrix<double> B = A;
    cblas_dscal(B.get_size(), x, B.get_values_data(), 1);
    return B;
}
template matrix<double> operator*(int x, const matrix<double>&);
template matrix<double> operator*(float x, const matrix<double>&);
template matrix<double> operator*(double x, const matrix<double>&);