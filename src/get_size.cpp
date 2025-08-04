#include "dense.hpp"

template<typename T>
size_t matrix<T>::get_size() const{
    return values.size();
};

template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;