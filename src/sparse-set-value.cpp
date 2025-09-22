#include "../inc/sparse.hpp"
template <typename T>
void rixoratory::matrix_s::set_value_at(size_t index, T value){
    //index = c + col_size*r
    size_t c = index%col_size;
    size_t r = index/col_size;
    size_t row_start = row_idx[r];
    size_t row_end = row_idx[r+1];

    for (size_t i = row_start; i<row_end; i++){
        if (col_idx[i] == c){
            values[i] = value;
            return;
        }
    }
    throw std::invalid_arguement("Can only set non-zero values");
}
template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;