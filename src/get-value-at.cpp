#include "../inc/dense.hpp"
template<typename T>
T matrix<T>::get_value_at(size_t index) const{
    return values[(int)index];
}
template float matrix<float>::get_value_at(size_t);
template double matrix<double>::get_value_at(size_t);
template std::complex<float> matrix<std::complex<float>>::get_value_at(size_t);
template std::complex<double> matrix<std::complex<double>>::get_value_at(size_t);s

