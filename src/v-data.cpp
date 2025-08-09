#include "../inc/dense.hpp"
template<typename T>
T* matrix<T>::v_data(){
    return values.data();
}
template float* matrix<float>::v_data();
template double* matrix<double>::v_data();
template std::complex<float>* matrix<std::complex<float>>::v_data();
template std::complex<double>* matrix<std::complex<double>>::v_data();
