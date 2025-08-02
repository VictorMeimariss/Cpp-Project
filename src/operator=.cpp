#include <../inc/dense.hpp>
using namespace std;

template<typename T>
matrix<T>& matrix<T>::operator=(matrix<T> const& A)
{
    values = A.values;
    dim_size = A.dim_size;
    precomputed_strides = A.precomputed_strides;
    
    return *this;
}

template matrix<float>& matrix<float>::operator=(matrix<float> const& A);
// template matrix<complex<float>>& matrix<complex<float>>::operator=(matrix<complex<float>> const& A);