#include "matrix.hpp"
#include <mkl.h>

template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, sparse::matrix<T>& B){
    if(!B.valid_handle) B.refresh_handle();
    dense::matrix<T> C(A.get_dim_size(0), B.shape()[1]);

    // Matrix description for mkl_sparse_?_mm
    matrix_descr descr; 
    descr.type = SPARSE_MATRIX_TYPE_GENERAL; 
    descr.mode = SPARSE_FILL_MODE_FULL; 
    descr.diag = SPARSE_DIAG_NON_UNIT;

    if constexpr(std::is_same_v<T,float>){
        float a = 1;
        float b = 0;
        sparse_s_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(),
         A.get_dim_size(1), A.get_dim_size(1), b,C.get_values_data(),C.get_dim_size(1));}
    else if constexpr(std::is_same_v<T,double>){
        double a = 1;
        double b = 0;
        sparse_d_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, A.get_const_values_data(), 
        A.get_dim_size(1), A.get_dim_size(1), b,C.get_values_data(),C.get_dim_size(1));}
    else if constexpr(std::is_same_v<T,std::complex<float>>){
        MKL_Complex8 a = {1,0}, b = {0,0};
        sparse_c_mm(SPARSE_OPERATION_NON_TRANSPOSE,a,B.handle,descr,SPARSE_LAYOUT_ROW_MAJOR,
        reinterpret_cast<const MKL_Complex8*>(A.get_const_values_data()), A.get_dim_size(1), A.get_dim_size(1), b,
        reinterpret_cast<MKL_Complex8*>(C.get_values_data()),C.get_dim_size(1));
    }
    else if constexpr(std::is_same_v<T,std::complex<double>>){
        MKL_Complex16 a = {1,0}, b = {0,0};
        sparse_z_mm(SPARSE_OPERATION_NON_TRANSPOSE, a, B.handle, descr, SPARSE_LAYOUT_ROW_MAJOR, 
        reinterpret_cast<const MKL_Complex16*>(A.get_const_values_data()), A.get_dim_size(1),A.get_dim_size(1), b,
        reinterpret_cast<MKL_Complex16*>(C.get_values_data()), C.get_dim_size(1));
    }
    return C;
}

template class dense::matrix<float>;
template class dense::matrix<double>;
template class dense::matrix<std::complex<float>>;
template class dense::matrix<std::complex<double>>;

/*
#include "matrix.hpp"

template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B){
    //rebuilding handles is not needed, ?csrmv works on arrays
    dense::matrix<T> C(A.dim_size[0], B.dim_size[1]);
    std::vector<MKL_INT> ptr_b(B.row_idx.begin(), B.row_idx.end()-1);
    std::vector<MKL_INT> ptr_e(B.row_idx.begin()+1, B.row_idx.end());
    char mat_descr[6] = {'G', ' ', ' ', 'C', ' ', ' '};

    //can't just move need separate, continuous memory
    if constexpr (std::is_same_v<T, float>){ 
            const float a = 1;
            const float b = 1;
            scsrmv('N', &B.row_size, &B.col_size, &a, mat_descr, B.vals.data(), B.col_idx.data(), ptrb.data(), pntre.data(), A.get_values_data(), b, C.get_values_data());
        }
        else if constexpr (std::is_same_v<T, double>){
            const double a = 1;
            const double b = 1;
            dcsrmv('N', &B.row_size, &B.col_size, &a, mat_descr, B.vals.data(), B.col_idx.data(), ptrb.data(), pntre.data(), A.get_values_data(), b, C.get_values_data());
        }
        else if constexpr (std::is_same_v<T, std::complex<float>>){
            const MKL_Complex8 a(1, 0);
            const MKL_Complex8 b(1, 0);
            ccsrmv('N', &B.row_size, &B.col_size, &a, mat_descr, B.vals.data(), B.col_idx.data(), ptrb.data(), pntre.data(), A.get_values_data(), b, C.get_values_data());
        }
        else if constexpr (std::is_same_v<T, std::complex<double>>){
            const MKL_Complex16 a(1, 0);
            const MKL_Complex16 b(1, 0);
            zcsrmv('N', &B.row_size, &B.col_size, &a, mat_descr, B.vals.data(), B.col_idx.data(), ptrb.data(), pntre.data(), A.get_values_data(), b, C.get_values_data());
        }
        return C;
};
template class dense::matrix<float>;
template class dense::matrix<double>;
template class dense::matrix<std::complex<float>>;
template class dense::matrix<std::complex<double>>;*/