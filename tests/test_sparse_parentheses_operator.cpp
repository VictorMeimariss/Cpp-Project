#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing sparse parentheses operator" << std::endl;
    //Parentheses operator is read only
    std::vector<float> values = {1.0, 2.0, 1.0, 3.0, 4.0, 5.0};
    std::vector<MKL_INT> col_idx = {0, 2, 3, 0, 2, 3};
    std::vector<MKL_INT> row_idx = {0, 1, 3, 5, 6};
    matrix<float> A(values, col_idx, row_idx, 4, 4);
    A.print_matrix();
    std::cout<<A(2,0)<<' '<<A(1,3)<<' '<<A(3,3)<<' '<<std::endl;
}