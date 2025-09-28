#include "matrix.hpp"
int main(){
    dense::matrix<int> A(2, 2);
    A.set_value_at(0, 1.0);
    A.set_value_at(1, 1.0);
    A.set_value_at(2, 1.0);
    A.set_value_at(3, 1.0);

    std::vector<int> values = {1};
    std::vector<MKL_INT> col_idx = {0};
    std::vector<MKL_INT> row_idx = {0, 0, 1};
    sparse::matrix<int> B(values, col_idx, row_idx, 2, 2);

    dense::matrix<int> C =  A * B;
    C.print2D();
    return 0;
}