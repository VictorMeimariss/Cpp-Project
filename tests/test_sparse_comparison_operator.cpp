#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Test Sparse operator==" << std::endl;

    std::vector<float> values = {1.0, 2.0, 3.0, 4.0};
    std::vector<MKL_INT> col_idx = {0, 1, 1, 2};
    std::vector<MKL_INT> row_idx = {0, 2, 3, 4};
    sparse::matrix<float> A(values, col_idx, row_idx, 3, 3);
    
    std::cout << "\nA matrix:" << std::endl;
    A.print2D();

    matrix<float> B = matrix<float>::I(3);
    std::cout << "\nB matrix:" << std::endl;
    B.print2D();

    bool condition = B == A;
    std::cout << "\nCorrect: B == A : 0" << std::endl;
    std::cout << "Output: B == A : " << condition << std::endl;

    sparse::matrix<float> C(values, col_idx, row_idx, 3, 3);

    std::cout << "\nC matrix:" << std::endl;
    C.print2D();

    condition = C == A;
    std::cout << "\nCorrect: C == A : 1" << std::endl;
    std::cout << "Output: C == A : " << condition << std::endl;

}