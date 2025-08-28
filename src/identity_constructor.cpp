#include "../inc/dense.hpp"
template<typename T>
matrix<T> matrix<T>::I(int N){
    matrix<T> res(N,N);
    for (int i=0; i<N;i++){
    res.get_values_data()[i*N+i] = static_cast<T>(1);
    }
    return res;
}
template matrix<float> matrix<float>::I(int);
template matrix<double> matrix<double>::I(int);
template matrix<std::complex<float>> matrix<std::complex<float>>::I(int);
template matrix<std::complex<double>> matrix<std::complex<double>>::I(int);
