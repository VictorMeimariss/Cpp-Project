#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
matrix<T> matrix<T>::operator+(matrix<T> const& A){
    // refresh handles if required
    if (!valid_handle)
        this->refresh_handle();
    if (!A.valid_handle)
        A.refresh_handle();
    this->valid_handle = true;
    A.valid_handle = true;  
    sparse_handle_t ret;
    if constexpr (std::is_same_v<T, float>){
            const float a = 1;
            sparse_s_add (SPARSE_OPERATION_NON_TRANSPOSE, A.handle, a, this->handle, &ret.handle);
        }
        else if constexpr (std::is_same_v<T, double>){
            const double a = 1;
            sparse_d_add (SPARSE_OPERATION_NON_TRANSPOSE, A.handle, a, this->handle, &ret.handle);
        }
        else if constexpr (std::is_same_v<T, std::complex<float>>){
            const MKL_Complex8 a(1, 0);
            sparse_c_add (SPARSE_OPERATION_NON_TRANSPOSE, A.handle, a, this->handle, &ret.handle);
        }
        else if constexpr (std::is_same_v<T, std::complex<double>>){
            const MKL_Complex16 a(1, 0);
            sparse_z_add (SPARSE_OPERATION_NON_TRANSPOSE, A.handle, a, this->handle, &ret.handle);
        }
        return matrix<T>(ret, rows, cols, false);
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
