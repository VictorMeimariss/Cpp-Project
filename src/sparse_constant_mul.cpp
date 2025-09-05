#include "../inc/sparse.hpp"

template <typename T>
rixoratory::matrix_s<T> rixoratory::matrix_s<T>::matrix_s operator*(T x){
    const MKL_INT n = this->rows*this->cols;
    std::vector<T> n_vals(this->values); //_scal operates in place
    if constexpr (std::is_same_v<T, float>)
        sscal(n, x, n_vals.data(), 1);
    else if constexpr (std::is_same_v<T, double>)
        dscal(n, x, n_vals.data(), 1);
    else if constexpr (std::is_same_v<T, std::complex<float>>)
        cscal(n, &x, n_vals.data() 1);
    else if constexpr (std::is_same_v<T, std::complex<double>>)
        zscal(n, &x, n_vals.data() 1);
    //reused code from scal_mn.cpp
    return matrix_s<T>(n_vals, this->col_idx, this->row_idx, this->rows, this->cols);
}

template class matrix_s<float>;
template class matrix_s<double>;
template class matrix_s<std::complex<float>>;
template class matrix_s<std::complex<double>>;
