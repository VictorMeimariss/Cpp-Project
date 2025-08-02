#include <../inc/dense.hpp>
#include <mkl.h>
// using namespace oneapi::mkl::blas::row_major;

template<typename T>
matrix<T> matrix<T>::operator-(matrix<T> const& A)
{
    float a = -1;
    cblas_saxpy(A.values.size(), a, A.values.data(), 1, (*this).values.data(), 1);

    return *this;
}

template matrix<float> matrix<float>::operator-(matrix<float> const& A);
// template matrix<std::complex<float>> matrix<std::complex<float>>::operator-(matrix<std::complex<float>> const& A);