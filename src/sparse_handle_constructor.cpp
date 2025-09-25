#include "../inc/sparse.hpp"
template <typename T>
void sparse::matrix::matrix(const sparse_matrix_t h, size_t rows, size_t cols, bool own){
    this->handle = h;
    this->rows = rows;
    this->cols = cols; 
    this->valid_handle = true;
    this->ownership = own;
    std::vector<T> row_start(rows); //pointer B
    std::vector<T> row_end(rows); //pointer E
    std::vector<T> col_idx;
    std::vector<T> val;
    if constexpr(std::is_same_v<T, float>){
        mkl_sparse_s_export_csr(h, SPARSE_INDEX_BASE_ZERO, rows, cols, row_start.data(), row_end.data(), col_idx.data(), val.data());
    }
    else if constexpr(std::is_same_v<T, double>){
        mkl_sparse_s_export_csr(h, SPARSE_INDEX_BASE_ZERO, rows, cols, row_start.data(), row_end.data(), col_idx.data(), val.data());
    }
    else if constexpr(std::is_same_v<T, std::complex<float>>){
        mkl_sparse_s_export_csr(h, SPARSE_INDEX_BASE_ZERO, rows, cols, row_start.data(), row_end.data(), col_idx.data(), val.data());
    }
    if constexpr(std::is_same_v<T, std::complex<double>>){
        mkl_sparse_s_export_csr(h, SPARSE_INDEX_BASE_ZERO, rows, cols, row_start.data(), row_end.data(), col_idx.data(), val.data());
    }
    vector<T> row_idx(rows+1);
    row_idx[0] = row_start[0];
    row_idx.insert(row_idx.end(), std::make_move_iterator(row_start.begin()), make_move_iterator(row_start.end())); // same functionality as insert(v.end(), v1.begin(), v1.end()), uses moving instead of copying for better performance since pointer B and pointer E are useless to us
    row_start = std::vector<T>();
    row_end = std::vector<T>();
   }
