#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::vector<float> values = {1.0, 2.0, 3.0, 4.0};
    std::vector<MKL_INT> col_idx = {0, 1, 1, 2};
    std::vector<MKL_INT> row_idx = {0, 2, 3, 4};
    sparse::matrix<float> A(values, col_idx, row_idx, 3, 3);
    
    std::cout << "A matrix:" << std::endl;
    A.print2D();

    matrix<float> B = matrix<float>::I(3);
    std::cout << "\nB matrix:" << std::endl;
    B.print2D();

    std::cout << "\nB = A" << std::endl;
    B = A;

    std::cout << "\nB matrix:" << std::endl;
    B.print2D();
}