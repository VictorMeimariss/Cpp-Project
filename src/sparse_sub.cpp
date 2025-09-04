#include "../inc/sparse.hpp"
template <typename T>
rixoratory::matrix_s<T>:: operator-(matrix_s<T> const& A){
    return *this+(A*(-1));
}
template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;