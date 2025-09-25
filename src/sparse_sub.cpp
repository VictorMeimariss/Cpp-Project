#include "../inc/sparse.hpp"
template <typename T>
sparse::matrix<T> sparse::matrix<T>::operator-(matrix<T> const& A){
    return *this+(A*(-1));
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
