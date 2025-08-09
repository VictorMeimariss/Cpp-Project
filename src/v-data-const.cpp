#include "../inc/dense.hpp"
template<typename T>
const T* matrix<T>::v_data(){
    return values.data();
}
template const float* matrix<float>::v_data();
template const double* matrix<double>::v_data();
template const std::complex<float>* matrix<std::complex<float>>::v_data();
template const std::complex<double>* matrix<std::complex<double>>::v_data();
