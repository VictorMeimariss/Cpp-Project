#include <../inc/dense.hpp>

template<typename T>
matrix<T>::matrix(matrix<T> const& A)
    : values(A.values), dim_size(A.dim_size), precomputed_strides(A.precomputed_strides)
{

}

template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;