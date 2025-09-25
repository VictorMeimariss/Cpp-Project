#include "../inc/dense.hpp"
using namespace dense;
template<typename T>
const T* matrix<T>::get_const_values_data(){
    return values.data();
}
template const float* matrix<float>::get_const_values_data();
template const double* matrix<double>::get_const_values_data();
template const std::complex<float>* matrix<std::complex<float>>::get_const_values_data();
template const std::complex<double>* matrix<std::complex<double>>::get_const_values_data();
