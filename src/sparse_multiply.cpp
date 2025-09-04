#include "../inc/sparse.hpp"
#define MKL_Complex16 std::complex<double>
#define MKL_Complex8 std::complex<float>
template <typename T>
rixoratory::matrix_s<T>:: operator+(matrix_s<T> const& A){
    // refresh handles if required
    if (!valid_handle)
        this->refresh_handle();
    if (!A.valid_handle)
        A.refresh_handle();
    this->valid_handle = true;
    A.valid_handle = true;
    sparse_handle_t ret;
    mkl_sparse_spmm(SPARSE_OPERATION_NON_TRANSPOSE, this->handle, A.handle, &ret);
    return matrix_z<T>(ret,this->rows, A.cols, false);
}
template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;