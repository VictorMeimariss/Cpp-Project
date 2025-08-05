#include "dense.hpp"

template <typename U>
matrix<float> operator*(U x, const matrix<float>& A){
    matrix<float> B = A;
    cblas_sscal(B.get_size(), x, B.get_values_data(), 1);
    return B;
}
template matrix<float> operator*(int x, const matrix<float>&);
template matrix<float> operator*(float x, const matrix<float>&);
template matrix<float> operator*(double x, const matrix<float>&);