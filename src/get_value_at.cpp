#include "../inc/dense.hpp"
using namespace dense;

template<typename T>
T matrix<T>::get_value_at(size_t index) const{
    return values[(int)index];
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;