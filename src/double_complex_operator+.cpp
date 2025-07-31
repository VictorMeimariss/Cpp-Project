#include "dense.hpp"
matrix matrix:: operator+(matrix const& A){
    matrix B = *this;
    float a = 1;
    cblas_daxpy(static_cast<int>(A.values.size()), a, A.values.data(), 1, B.values.data(), 1);
    return B;
}