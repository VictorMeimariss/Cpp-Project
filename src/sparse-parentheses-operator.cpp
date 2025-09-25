#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
const T matrix<T>::operator () (size_t r, size_t c) const{
    size_t row_start = row_idx[r];
    size_t row_end = row_idx[r+1];

    for (size_t i = row_start; i<row_end; i++){
        if (col_idx[i] == c){
            return vaules[i];
        }
    }
    return T{};
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;