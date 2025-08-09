#include "../inc/dense.hpp"
matrix<T>::matrix (matrix<T>&& A) noexcept
    : values(std::move(A.values)), dim_size(std::move(A.dim_size)), precomputed_strides(std::move(A.precomputed_strides)) {}
