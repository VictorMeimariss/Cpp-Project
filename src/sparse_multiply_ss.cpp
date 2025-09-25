#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
matrix<T> matrix<T>:: operator*(matrix<T> const& A){
    // refresh handles if required
    if (!valid_handle)
        this->refresh_handle();
    if (!A.valid_handle)
        A.refresh_handle();
    this->valid_handle = true;
    A.valid_handle = true;
    sparse_handle_t ret;
    sparse_spmm(SPARSE_OPERATION_NON_TRANSPOSE, this->handle, A.handle, &ret);
    return matrix<T>(ret,this->rows, A.cols, false);
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
