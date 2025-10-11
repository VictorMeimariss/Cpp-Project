#include "matrix.hpp"
int main(){
    dense::matrix<float> A(2, 2);
    A.set_value_at(0, 1.0);
    A.set_value_at(1, 1.0);
    A.set_value_at(2, 1.0);
    A.set_value_at(3, 1.0);

    std::vector<float> values = {1.0};
    std::vector<MKL_INT> col_idx = {0};
    std::vector<MKL_INT> row_idx = {0, 0, 1};
    sparse::matrix<float> B(values, col_idx, row_idx, 2, 2);

    dense::matrix<float> C =  A * B;
    std::cout << "Test Expected Answer for dense x sparse:\n" << "[1, 0; 1, 0]\n\n" << "Test Result:" << std::endl;
    C.print2D();

    C = B * A;
    std::cout << "Test Expected Answer for sparse x dense:\n" << "[0, 0; 1, 1]\n\n" << "Test Result:" << std::endl;
    C.print2D();
    return 0;
}