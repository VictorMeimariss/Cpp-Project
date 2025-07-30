#include <../inc/dense.hpp>

matrix& matrix::operator=(matrix const& A)
{
    values = A.values;
    dim_size = A.dim_size;
    precomputed_strides = A.precomputed_strides;
    
    return *this;
}