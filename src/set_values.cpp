#include "../inc/dense.hpp"
template<typename T>
template<typename... Types>
void matrix<T>::set_values(Types... valuess){
    values = std::forward<Types>(valuess);
}
template void matrix<float>::set_values()
//τελικα στο header

