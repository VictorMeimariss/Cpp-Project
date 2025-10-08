#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
matrix<T>::matrix (matrix const& A)
    :handle(A.handle), valid_handle(A.valid_handle), ownership(A.ownership), values(A.values), col_idx(A.col_idx), row_idx(A.row_idx)
{

}