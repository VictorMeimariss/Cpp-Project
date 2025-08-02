#include <../inc/dense.hpp>

template<typename T>
matrix<T>::matrix(matrix<T> const& A)
    : values(A.values), dim_size(A.dim_size), precomputed_strides(A.precomputed_strides)
{

}

// template matrix<int>::matrix(matrix<int> const& A);
template matrix<float>::matrix(matrix<float> const& A);