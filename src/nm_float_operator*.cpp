#include "dense.hpp"

template <>
matrix<float> matrix<float>:: operator*(float x){
    matrix<float> B = *this;
    cblas_sscal(B.values.size(), x, B.values.data(), 1);
    return B;
}
template class matrix<float>;