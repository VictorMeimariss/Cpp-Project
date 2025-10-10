#include "matrix.hpp"
#include <mkl.h>

namespace dense {

template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B) {
    if (!B.is_handle_valid()) B.ensure_handle();

    const MKL_INT m = A.get_dim_size(0);
    const MKL_INT k = A.get_dim_size(1);
    const MKL_INT n = B.shape().second;

    dense::matrix<T> C(m, n);

    // Matrix descriptor
    matrix_descr descr{};
    descr.type = SPARSE_MATRIX_TYPE_GENERAL;
    descr.mode = SPARSE_FILL_MODE_FULL;
    descr.diag = SPARSE_DIAG_NON_UNIT;

    if constexpr (std::is_same_v<T, float>) {
        const float a = 1.0f, b = 0.0f;
        sparse_s_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr,
                    SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(),
                    k, n, b, C.get_values_data(), n);
    } else if constexpr (std::is_same_v<T, double>) {
        const double a = 1.0, b = 0.0;
        sparse_d_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr,
                    SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(),
                    k, n, b, C.get_values_data(), n);
    } else if constexpr (std::is_same_v<T, std::complex<float>>) {
        const MKL_Complex8 a = {1, 0}, b = {0, 0};
        sparse_c_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr,
                    SPARSE_LAYOUT_ROW_MAJOR,
                    reinterpret_cast<const MKL_Complex8*>(A.get_const_values_data()),
                    k, n, b,
                    reinterpret_cast<MKL_Complex8*>(C.get_values_data()), n);
    } else if constexpr (std::is_same_v<T, std::complex<double>>) {
        const MKL_Complex16 a = {1, 0}, b = {0, 0};
        sparse_z_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr,
                    SPARSE_LAYOUT_ROW_MAJOR,
                    reinterpret_cast<const MKL_Complex16*>(A.get_const_values_data()),
                    k, n, b,
                    reinterpret_cast<MKL_Complex16*>(C.get_values_data()), n);
    }

    return C;
}

template dense::matrix<float> operator*(const dense::matrix<float>&, const sparse::matrix<float>&);
template dense::matrix<double> operator*(const dense::matrix<double>&, const sparse::matrix<double>&);
template dense::matrix<std::complex<float>> operator*(const dense::matrix<std::complex<float>>&, const sparse::matrix<std::complex<float>>&);
template dense::matrix<std::complex<double>> operator*(const dense::matrix<std::complex<double>>&, const sparse::matrix<std::complex<double>>&);

} 
