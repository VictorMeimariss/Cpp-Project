#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing sparse value setter" << std::endl;
    //setter uses flat indexing
    std::vector<float> values = {1.0, 2.0, 1.0, 3.0, 4.0, 5.0};
    std::vector<MKL_INT> col_idx = {0, 2, 3, 0, 2, 3};
    std::vector<MKL_INT> row_idx = {0, 1, 3, 5, 6};
    matrix<float> A(values, col_idx, row_idx, 4, 4);
    A.print_matrix();
    A.set_value_at(0, 8.0);
    A.set_value_at(6, 3.0);
    A.set_value_at(7, 4.0);
    A.print_matrix();
}