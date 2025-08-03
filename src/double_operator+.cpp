#include "dense.hpp"

template<>
matrix<double> matrix<double>:: operator+(matrix<double> const& A){
    matrix<double> B = *this;
    double a = 1;
    cblas_daxpy(static_cast<int>(A.values.size()), a, A.values.data(), 1, B.values.data(), 1);
    return B;
}
template class matrix<double>;