#include "matrix.hpp"

template<typename T>
dense::matrix<T> operator*(const dense::matrix<T>& A, const sparse::matrix<T>& B){

};
/*template <typename T>
std::vector<T> matrix<T>::operator*(std::vector<T> const& v){
    //rebuilding handles is not needed, ?dcsrmv works on arrays
    std::vector<T>y(v.size(),0);
    std::vector<T> ptr_b(this->row_idx.begin(), this->row_idx.end()-1);
    std::vector<T> ptr_e(this->row_idx.begin()+1, this->row_idx.end());
    //can't just move need separate, continuous memory
    if constexpr (std::is_same_v<T, float>){
            const float a = 1;
            const float b = 0;
            scsrmv('n', this->rows,this->cols, alpha, "GxxC", this->vals.data(), this->col_idx.data(), ptrb.data(), pntre.data(), v.data(), b, y.data())
        }
        else if constexpr (std::is_same_v<T, double>){
            const double a = 1;
            const double b = 1;
            dcsrmv('n', this->rows,this->cols, alpha, "GxxC", this->vals.data(), this->col_idx.data(), ptrb.data(), pntre.data(), v.data(), b, y.data())
        }
        else if constexpr (std::is_same_v<T, std::complex<float>>){
            const MKL_Complex8 a(1, 0);
            const MKL_Complex8 b(1, 0);
            ccsrmv('n', this->rows,this->cols, alpha, "GxxC", this->vals.data(), this->col_idx.data(), ptrb.data(), pntre.data(), v.data(), b, y.data())
        }
        else if constexpr (std::is_same_v<T, std::complex<double>>){
            const MKL_Complex16 a(1, 0);
            const MKL_Complex16 b(1, 0);
            zcsrmv('n', this->rows,this->cols, alpha, "GxxC", this->vals.data(), this->col_idx.data(), ptrb.data(), pntre.data(), v.data(), b, y.data())
        }
        return y;
}
template class matrix<float>;
template class matrix<double>;
template class matrix<std::complex<float>>;
template class matrix<std::complex<double>>;*/
