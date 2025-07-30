#include <../inc/dense.hpp>

matrix::matrix (matrix const& A)
    : values(A.values), dim_size(A.dim_size), precomputed_strides(A.precomputed_strides)
{

}
