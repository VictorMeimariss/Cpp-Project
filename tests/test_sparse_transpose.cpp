#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing Sparse Transpose Matrix function" << std::endl;

    std::vector<float> values = {1.0};
    std::vector<MKL_INT> col_idx = {0};
    std::vector<MKL_INT> row_idx = {0, 0, 1};
    matrix<float> A(values, col_idx, row_idx, 2, 1);
    matrix<float> C = A.transpose();
    
    std::cout << "Test Expected Answer:\n" << "Values: 1\nCol_idx: 1\nRow_idx: 0 1 \n\n" << "Test Result:" << std::endl;
    C.print2D();
}