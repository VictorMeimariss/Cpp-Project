#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
const std::vector<T>& matrix<T>::diag() const{
    std::vector<T> ret;
    for (int i = 0; i<col_size; i++)
        ret.push_back(this->get_value_at(i*col_size + i));
    return ret;
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;