#include "../inc/sparse.hpp"
using namespace sparse;

int main()
{
    std::cout << "Testing sparse value getter" << std::endl;
    //getter uses flat indexing
    std::vector<float> values = {1.0, 2.0, 1.0, 3.0, 4.0, 5.0};
    std::vector<MKL_INT> col_idx = {0, 2, 3, 0, 2, 3};
    std::vector<MKL_INT> row_idx = {0, 1, 3, 5, 6};
    matrix<float> A(values, col_idx, row_idx, 4, 4);
    A.print_matrix();
    std::cout<<A.get_value_at(0)<<' '<<A.get_value_at(1)<<' '<<A.get_value_at(15)<<std::endl;
}