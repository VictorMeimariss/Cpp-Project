// #include "matrix.hpp"
// #include <mkl.h>

// namespace dense {
// template<typename T>
// dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B){
//     if(!B.valid_handle) B.refresh_handle();
//     dense::matrix<T> C(A.get_dim_size(0), B.shape().second);

//     // Matrix description for mkl_sparse_?_mm
//     matrix_descr descr; 
//     descr.type = SPARSE_MATRIX_TYPE_GENERAL; 
//     descr.mode = SPARSE_FILL_MODE_FULL; 
//     descr.diag = SPARSE_DIAG_NON_UNIT;

//     if constexpr(std::is_same_v<T,float>){
//         float a = 1;
//         float b = 0;
//         sparse_s_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(),
//          A.get_dim_size(1), A.get_dim_size(1), b,C.get_values_data(),C.get_dim_size(1));}
//     else if constexpr(std::is_same_v<T,double>){
//         double a = 1;
//         double b = 0;
//         sparse_d_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(), 
//         A.get_dim_size(1), A.get_dim_size(1), b,C.get_values_data(),C.get_dim_size(1));}
//     else if constexpr(std::is_same_v<T,std::complex<float>>){
//         MKL_Complex8 a = {1,0}, b = {0,0};
//         sparse_c_mm(SPARSE_OPERATION_NON_TRANSPOSE,a,B.handle,descr,SPARSE_LAYOUT_ROW_MAJOR,
//         reinterpret_cast<const MKL_Complex8*>(A.get_const_values_data()), A.get_dim_size(1), A.get_dim_size(1), b,
//         reinterpret_cast<MKL_Complex8*>(C.get_values_data()),C.get_dim_size(1));
//     }
//     else if constexpr(std::is_same_v<T,std::complex<double>>){
//         MKL_Complex16 a = {1,0}, b = {0,0};
//         sparse_z_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, 
//         reinterpret_cast<const MKL_Complex16*>(A.get_const_values_data()), A.get_dim_size(1),A.get_dim_size(1), b,
//         reinterpret_cast<MKL_Complex16*>(C.get_values_data()), C.get_dim_size(1));
//     }
//     return C;
// }

// template dense::matrix<float> dense::operator*(
//     const dense::matrix<float>&, const sparse::matrix<float>&);
// template dense::matrix<double> dense::operator*(
//     const dense::matrix<double>&, const sparse::matrix<double>&);
// template dense::matrix<std::complex<float>> dense::operator*(
//     const dense::matrix<std::complex<float>>&, const sparse::matrix<std::complex<float>>&);
// template dense::matrix<std::complex<double>> dense::operator*(
//     const dense::matrix<std::complex<double>>&, const sparse::matrix<std::complex<double>>&);}