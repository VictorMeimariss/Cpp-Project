#include "matrix.hpp"
#include <mkl.h> //Chat gbt written

namespace dense {
template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B) {
    if (!B.is_handle_valid()) B.ensure_handle();
    dense::matrix<T> C(A.get_dim_size(0), B.shape().second);

    // Matrix descriptor for MKL
    matrix_descr descr{};
    descr.type = SPARSE_MATRIX_TYPE_GENERAL;
    descr.mode = SPARSE_FILL_MODE_FULL;
    descr.diag = SPARSE_DIAG_NON_UNIT;

    const MKL_INT m = A.get_dim_size(0);
    const MKL_INT k = A.get_dim_size(1);
    const MKL_INT n = B.shape().second;

    // Build A^T (dense, k x m)
    std::vector<T> At(k * m);
    for (size_t i = 0; i < k; ++i)
        for (size_t j = 0; j < m; ++j)
            At[i * m + j] = A.get_value_at(j * k + i);

    // Buffer for C^T (n x m)
    std::vector<T> Ct(n * m, T(0));

    if constexpr (std::is_same_v<T, float>) {
        const float a = 1.0f, b = 0.0f;
        sparse_s_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr, SPARSE_LAYOUT_ROW_MAJOR,
                    At.data(), m, m, b, Ct.data(), m);
    } else if constexpr (std::is_same_v<T, double>) {
        const double a = 1.0, b = 0.0;
        sparse_d_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr, SPARSE_LAYOUT_ROW_MAJOR,
                    At.data(), m, m, b, Ct.data(), m);
    } else if constexpr (std::is_same_v<T, std::complex<float>>) {
        const MKL_Complex8 a = {1, 0}, b = {0, 0};
        sparse_c_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr, SPARSE_LAYOUT_ROW_MAJOR,
                    reinterpret_cast<const MKL_Complex8*>(At.data()), m, m, b,
                    reinterpret_cast<MKL_Complex8*>(Ct.data()), m);
    } else if constexpr (std::is_same_v<T, std::complex<double>>) {
        const MKL_Complex16 a = {1, 0}, b = {0, 0};
        sparse_z_mm(SPARSE_OPERATION_TRANSPOSE, a, B.get_handle(), descr, SPARSE_LAYOUT_ROW_MAJOR,
                    reinterpret_cast<const MKL_Complex16*>(At.data()), m, m, b,
                    reinterpret_cast<MKL_Complex16*>(Ct.data()), m);
    }

    // Transpose Ct (n x m) -> C (m x n)
    for (size_t i = 0; i < m; ++i)
        for (size_t j = 0; j < n; ++j)
            C.set_value_at(i * n + j, Ct[j * m + i]);

    return C;
}

template dense::matrix<float> operator*(const dense::matrix<float>&, const sparse::matrix<float>&);
template dense::matrix<double> operator*(const dense::matrix<double>&, const sparse::matrix<double>&);
template dense::matrix<std::complex<float>> operator*(const dense::matrix<std::complex<float>>&, const sparse::matrix<std::complex<float>>&);
template dense::matrix<std::complex<double>> operator*(const dense::matrix<std::complex<double>>&, const sparse::matrix<std::complex<double>>&);

}