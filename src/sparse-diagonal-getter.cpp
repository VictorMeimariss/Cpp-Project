#include "../inc/sparse.hpp"
template <typename T>
const std::vector<T> rixoratory::matrix_s::diag() const{
    std::vector<T> ret;
    for (int i = 0; i<col_size; i++)
        ret.push_back(this->get_value_at(i*col_size + i));
    return ret;
}
template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;