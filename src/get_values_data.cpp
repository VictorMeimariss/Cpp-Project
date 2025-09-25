#include "dense.hpp"
using namespace dense;

template <typename T>
T* matrix<T>::get_values_data(){
    return values.data();
}

template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;