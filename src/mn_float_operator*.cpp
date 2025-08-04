#include "dense.hpp"

template <>
matrix<float> operator*(float x, const matrix<float>& A){
    matrix<float> B = A;
    cblas_sscal(B.get_size(), x, B.get_values_data(), 1);
    return B;
}
template class matrix<float>;