#include <iostream>
#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "\nTest sparse matrix - vector multiplication" << std::endl;

    std::vector<float> values = {1.0, 2.0, 3.0, 4.0};
    std::vector<MKL_INT> col_idx = {0, 1, 1, 2};
    std::vector<MKL_INT> row_idx = {0, 2, 3, 4};
    sparse::matrix<float> A(values, col_idx, row_idx, 3, 3);

    std::cout << "\nA matrix<float>:" << std::endl;
    A.print2D();

    std::vector<float> V = {2.0, 3.0, 4.0};
    std::cout << "\nColumn vector V<float> = [ 2; 3; 4 ]" << std::endl;
    std::vector<float> res = A*V;

    std::cout << "\nExpected result for A*V: [ 8, 9, 16 ]" << std::endl;
    std::cout << "Result vector res: [ ";
    for (size_t i = 0; i < res.size(); ++i) {
        std::cout << res[i];
        if (i < res.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;

}