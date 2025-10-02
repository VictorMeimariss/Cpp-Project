#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
matrix<T> matrix<T>::I(int N)
{
    for (int count = 0; count < N; count++)
    {
        values.push_back(1);
        col_idx.push_back(count);
        row_idx.push_back(count);
    }

    row_idx.push_back(values.size()); // The last element of the row_idx vector in CSR must always be nnz, i.e. the size of the value vector
}

template class sparse::matrix<float>;
template class sparse::matrix<double>;
template class sparse::matrix<std::complex<float>>;
template class sparse::matrix<std::complex<double>>;