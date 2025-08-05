#include <../inc/dense.hpp>
using namespace std;

/**
 * @brief Gets number of dimensions.
 */
template<typename T>
size_t matrix<T>::get_nod() const
{
    return dim_size.size();
}

// template class matrix<int>;
template size_t matrix<int>::get_nod() const;
template size_t matrix<float>::get_nod() const;
template size_t matrix<complex<float>>::get_nod() const;
template size_t matrix<complex<double>>::get_nod() const;