#include "../inc/sparse.hpp"
#define MKL_Complex16 std::complex<double>
#define MKL_Complex8 std::complex<float>
template <typename T>
void rixoratory::matrix_s::refresh_handle(){
    std::vector<T> val(this->values);
    std::vector<T> row_start(this->row_idx.begin(), this->row_idx.end()-1);
    std::vector<T> row_end(this->row_idx.begin()+1, this->row_idx.end());
    std::vector<T> col_idx(this->col_idx);
    //The arrays copied are definitely owned by us
    if (valid_handle){
        return;
    }
    mkl_sparse_destroy(this->handle);
    if constexpr(std::is_same_v<T, float>){
        mkl_sparse_s_create_csr(this->handle, SPARSE_INDEX_BASE_ZERO, this->rows, this->cols,rows_start.data(), rows_end.data(), col_idx.data(), val.data());
    }
    else if constexpr(std::is_same_v<T,double>){
        mkl_sparse_d_create_csr(this->handle, SPARSE_INDEX_BASE_ZERO, this->rows, this->cols,rows_start.data(), rows_end.data(), col_idx.data(), val.data());
    }
    else if constexpr(std::is_same_v<T, std::complex<float>>){
        mkl_sparse_c_create_csr(this->handle, SPARSE_INDEX_BASE_ZERO, this->rows, this->cols,rows_start.data(), rows_end.data(), col_idx.data(), val.data());
        
    }
    else if constexpr(std::is_same_v<T, std::complex<double>>){
        mkl_sparse_z_create_csr(this->handle, SPARSE_INDEX_BASE_ZERO, this->rows, this->cols,rows_start.data(), rows_end.data(), col_idx.data(), val.data());
    }
    this->valid_handle = true;
    val = std::vector<T>();
    row_start = std::vector<T>();
    row_end = std::vector<T>();
    col_idx = std::vector<T>();
    return;
}
template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;