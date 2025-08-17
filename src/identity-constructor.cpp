/*#include "../inc/dense.hpp"
template<typename T>
matrix<T> matrix<T>::I(int N){
    matrix<T> res;
    res.dim_size = std::vector<int>(2,N);
    res.precomputed_strides = std::vector<int>(2);
    res.values = std::vector<T>(N*N,0);
    for (int i=0; i<N;i++){
        res.values[i*N+i] = static_cast<T>(1);
    }
    res.precomputed_strides[0] = 1;
    res.precomputed_strides[1] = N;
    return res;
}
template matrix<float> matrix<float>::I(int);
template matrix<double> matrix<double>::I(int);
template matrix<std::complex<float>> matrix<std::complex<float>>::I(int);
template matrix<std::complex<double>> matrix<std::complex<double>>::I(int);*/