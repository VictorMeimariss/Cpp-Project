#include "dense.hpp"

template <>
matrix<double> matrix<double>:: operator*(double x){
    matrix<double> B = *this;
    cblas_dscal(B.values.size(), x, B.values.data(), 1);
    return B;
}
template class matrix<double>;