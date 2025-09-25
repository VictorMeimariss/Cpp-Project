#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
matrix<T> matrix<T>::operator-(matrix<T> const& A){
    return *this+(A*(-1));
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
