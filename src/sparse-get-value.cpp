#include "../inc/sparse.hpp"
template <typename T>
void sparse::matrix::set_value_at(size_t index, T value){
    //index = c + col_size*r
    size_t c = index%col_size;
    size_t r = index/col_size;
    size_t row_start = row_idx[r];
    size_t row_end = row_idx[r+1];

    for (size_t i = row_start; i<row_end; i++){
        if (col_idx[i] == c){
            return values[i];
        }
    }
    return 0;
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;
