#include "../inc/sparse.hpp"
using namespace sparse;

template <typename T>
void matrix<T>::print2D() 
{
    std::cout << "Values: " ;
    for (size_t n = 0; n < values.size(); n++)
    {
            std::cout << values[n] << " ";
    }

    std::cout << "\nCol_idx: " ;
    for (size_t n = 0; n < col_idx.size(); n++)
    {
            std::cout << col_idx[n] << " ";
    }

    std::cout << "\nRow_idx: " ;
    for (size_t n = 0; n < row_idx.size(); n++)
    {
            std::cout << row_idx[n] << " ";
    }

    std::cout << std::endl;
}